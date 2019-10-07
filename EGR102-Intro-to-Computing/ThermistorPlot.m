%           EGR102
%        BRENNEN GREEN
%    USE: THERMISTOR DATA PLOT

clear;
% Read the voltage data and convert it to resistance
dataVoltage = xlsread("ThermistorData.xlsx");
ThermistorR = 10000 * dataVoltage ./ (5 - dataVoltage);

% Turn the resistance to a temperature then convert to F
KelvinTemp = resistanceToTemp(ThermistorR);
FahreneitTemp = (9/5)*(KelvinTemp - 273.15) + 32;

% Plot the previously computed data
plot(FahreneitTemp);
ylim([-30,150]);
ylabel('Temperature');
title("Thermistor Temperature Graph");