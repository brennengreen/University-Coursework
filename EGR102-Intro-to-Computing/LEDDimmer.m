brightness_step = (1-0)/20;

for i=1:20
   writePWMDutyCycle(a, 'D9', i*brightness_step);
   pause(.1);
end


for i=1:20
   
   writePWMDutyCycle(a, 'D9', 1-i*brightness_step);
   pause(.1);
end

% while (true)
%     writeDigitalPin(a, "D9", 1)
%     pause(.5);
%     writeDigitalPin(a, "D9", 0)
%     pause(.5);
% end