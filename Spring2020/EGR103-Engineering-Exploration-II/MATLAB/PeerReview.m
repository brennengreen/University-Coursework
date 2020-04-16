% Vision Code Peer Review

PIXELS_LEFT_TO_MIDDLE = 393;

%%% Input Excel Sheet
file_path = "VisionInput.xlsx";
input_data = xlsread(file_path);
%%%

dist_to_target = input_data(1);
pixels_target_to_left = input_data(2);

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