%a = arduino('com3','uno');
thermistor = 'A0';
photoresistor = 'A1';

data = xlsread('Torpidity.xlsx');
voltsTor = data(:, 1); % Voltage readingss in column A
torpidity = data(:, 2); % Torpidity temperatures in column B

data = xlsread('Temperature.xlsx');
voltsTemp = data(:, 1);
temperature = data(:, 2);

torFit = fit(voltsTor, torpidity, 'poly1');
tempFit = fit(voltsTemp, temperature, 'poly1');

while 1==1
    reading = readVoltage(a, thermistor);
    temperature = tempFit(reading);
    disp(temperature)
    % INSERT SERVO STUFF
    pause(2)
    reading = readVoltage(a, photoresistor);
    torpidity = torFit(reading);
    disp(torpidity)
    % INSERT SERVO STUFF
    pause(2)
end