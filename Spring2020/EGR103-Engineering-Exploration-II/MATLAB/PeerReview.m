% Vision Code Peer Review
clear;
clc;
a = arduino;

s = servo(a,'D3','MaxPulseDuration',2e-3,'MinPulseDuration',1e-3);
writePosition(s, processVisionData());
canFire = true;
while (canFire)
    writeDigitalPin(a, 'D11', 1)
    if (readDigitalPin(a, 'D8'))
        canFire = false;
       disp("Fire") 
    end
end
writeDigitalPin(a, 'D11', 0)
writePosition(s, 0.1);
    

function [servoPos] = processVisionData()
    PIXELS_LEFT_TO_MIDDLE = 393;

    %%% Input Excel Sheet
    file_path = "VisionInput.xlsx";
    input_data = xlsread(file_path);
    %%%
    
    %%% Input Model
    file_path = "LinearModel.xlsx";
    model_data = xlsread(file_path);
    %%%
    
    dist_to_target = input_data(1);
    pixels_target_to_left = input_data(2);
    
    angle = distanceToDeg(dist_to_target);
    
    sprintf("Target is %d m away\n", dist_to_target);
    if pixels_target_to_left == PIXELS_LEFT_TO_MIDDLE
        disp("Target is algined and ready to fire!")
    else
        offset = pixels_target_to_left - PIXELS_LEFT_TO_MIDDLE;
        direction = "";
        if offset > 0
            direction = "left";
        else
            direction = "right";
        end
        sprintf("Launcher needs to adjust %d pixels to the %s", abs(offset), direction)
    end
    servoPos = normalizeAngle(angle);
end

function [degree] = distanceToDeg(distance)
    solOne = abs((-0.1522 + sqrt( -0.0064*(distance) + 0.02011204 ) ) / (0.0032));
    solTwo = abs((-0.1522 - sqrt( -0.0064*(distance) + 0.02011204 ) ) / (0.0032));
    
    if solOne < 15 || solOne > 50
        degree = solTwo;
    elseif solTwo < 15 || solTwo > 50
        degree = solOne;
    elseif (solTwo > 15 && solOne > 15) && (solOne < 50 && solTwo < 50)
        if solTwo > solOne
            degree = solTwo;
        else
            degree = solOne;
        end
    end
end

function [normal] = normalizeAngle(angle)
 x = angle - 15;
 ratioMax = x / 35;
 normal = (ratioMax * 0.26) + 0.1;
end
