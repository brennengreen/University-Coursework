%{
% Author: Brennen Green
% Assignment: EGR102-001 Roughness Classifier
% Date: 10/30/2019
% Purpose: An algorithm that classifies the type of material the sensor is
% reading
table
%}

%Connect_Arduino();
analog = zeros(1,5); %holds voltage reads

   for index = 1:5 %run values 1 to 5
       analog(index) = readVoltage(a,'A0'); %read from arduino
       pause (.2); %slows down read speed
         count=5-index;  % this is to give you a count down on your screen
         disp(count);
   end %end inside loop
        Highest=max(analog);
        lowest=min(analog);
        AveValue=mean(analog); %sets the average from the test

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%        Place your classifier code here   %%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%                                          %%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%  Your values X1 is highest               %%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%    X2 is lowest                          %%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%    X3 is the average or mean             %%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Classify the material based on the highest value
if (AveValue < 3.81232)
    disp("Smooth"); % Smooth
elseif (AveValue >= 3.8)
    if (AveValue < 3.9)
        disp("Medium"); % Medium
    elseif (AveValue >=  3.9)
        disp("Rough"); % Rough
    end
end
