a = arduino('com3','uno') %only needed if arduino not connected
analog = zeros(1,100); %holds voltage reads
test = 0; %sets initial test number
while 1==1 %continually run
   test =test +1; %defines test number    
   AllValues = 0; % set initial average of this test to 0
   
for index = 1:100 %run values 2 through 99
   analog(index) = readVoltage(a,'A1'); %read from arduino
   AllValues = analog(index)+ AllValues; %adds all values for test
   pause (.1); %slows down read speed
   plot (analog); %plots values 
   ylim([-1 6]); %set y limits of plot
   ylabel('Voltage'); %label Y axis
end %end for loop

   AveValue = AllValues/100; %sets the average from the test
   fprintf ('test %d = %.4f \n', test, AveValue) %prints values
end %end while loop 
