%Connect_Arduino();
PHOTO_PIN_NUM = 'A0';
RED_LED_PIN_NUM = 'D13';
GREEN_LED_PIN_NUM = 'D12';
SERV_PIN = 'D9';
FLAW_MINIMUM = 4.9300;
BOX_CAPACITY = 5;

%s = servo(a, SERV_PIN, 'MinPulseDuration', 700*10^-6, 'MaxPulseDuration', 2300*10^-6);
writePosition(s, .85);
writeDigitalPin(a, GREEN_LED_PIN_NUM, 0);
writeDigitalPin(a, RED_LED_PIN_NUM, 0);

material_in_box = 0;

while(material_in_box < BOX_CAPACITY)
    pause(.5);
    value = readVoltage(a, PHOTO_PIN_NUM);
%     disp(value)
    if value < FLAW_MINIMUM && value > 4.900
          writePosition(s, .85);
          writeDigitalPin(a, RED_LED_PIN_NUM, 1);
    elseif value > FLAW_MINIMUM
          writeDigitalPin(a, RED_LED_PIN_NUM, 0);
          writePosition(s, .5);
          pause(.5);
          material_in_box = material_in_box + 1;
          disp(+1);
    else
          writeDigitalPin(a, RED_LED_PIN_NUM, 0);
          writePosition(s, .85);
    end
end

writePosition(s, .85);
writeDigitalPin(a, GREEN_LED_PIN_NUM, 1);
disp("The material box is full");

    