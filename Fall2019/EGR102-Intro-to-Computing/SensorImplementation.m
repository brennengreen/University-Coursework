%{
    EGR-102-001 Final Project
    Team members: Brennen Green, Chris Gonzalez,
    Dylan Taylor, Jainam Dhruva
    Purpose: Read the temperature and the turbidity of given samples
    and report them on a servo controlled gauge
%}

clear
a = arduino('com5','uno');
s1 = servo(a, 'D9', 'MinPulseDuration', 700*10^-6, 'MaxPulseDuration', 2300*10^-6);
s2 = servo(a, 'D3', 'MinPulseDuration', 700*10^-6, 'MaxPulseDuration', 2300*10^-6);
writePosition(s1, 0);
writePosition(s2, 0);
thermistor = 'A0';
photoresistor = 'A1';

data = xlsread('tor.xlsx');
voltsTor = data(:, 1); % Voltage readingss in column A
torpidity = data(:, 2); % Torpidity temperatures in column B

data = xlsread('Temperature.xlsx');
voltsTemp = data(:, 1);
temperature = data(:, 2);

torFit = fit(voltsTor, torpidity, 'poly1');
tempFit = fit(voltsTemp, temperature, 'poly1');

while 1==1
    % Range: 30-110 F
    temps = zeros(5);
    for i=1:5
         reading = readVoltage(a, thermistor);
         temperature = tempFit(reading);
         temps(i) = temperature;
    end
    avg = mean(temps);
    disp(avg(1));
    avg = avg(1) - 30; % Normalizing the value
    percentage = avg / 80.0;
    writePosition(s1, percentage);
    disp(percentage);
    pause(3)
    
    % Range: 0-700 NTU
    torps = zeros(5);
    for i=1:5
        reading = readVoltage(a, photoresistor);
        torpidity = torFit(reading);
        torps(i) = torpidity;
    end
    avg = mean(torps);
    disp(avg(1));
    avg = avg(1); % Normalizing
    percentage = avg / 700;
    writePosition(s2, percentage);
    pause(3)
end

writePosition(s1, 0);
writePosition(s2, 0);