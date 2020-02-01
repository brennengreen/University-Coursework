Connect_Arduino()
red = 'D13';
yellow = 'D8';
green = 'D7';
push_button = 'D4';
servo_pin = 'D9';
serv = servo(a, servo_pin, 'MinPulseDuration', 130*10^-5, 'MaxPulseDuration', 170*10^-5);
writePosition(serv, 0);

while 1==1
    D4 = readDigitalPin(a, push_button);
    fprintf("Digital Pin 4: %d\n", D4)
    writeDigitalPin(a, green, 1);
    if D4 == 1
        writeDigitalPin(a, green, 0);
        light_led(a, yellow);
        pause(.5);
        dim_led(a, yellow);
        light_led(a, red);
        open_gate(serv);
        dim_led(a, red);
    end
end

function [] = open_gate(s)
    writePosition(s, 1);
    pause(2);
    writePosition(s, 0);
end

function [] = light_led(a, pin)
    writeDigitalPin(a, pin, 1);
end

function [] = dim_led(a, pin)
    writeDigitalPin(a, pin, 0);
end
