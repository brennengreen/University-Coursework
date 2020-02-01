%{
% Author: Brennen Green
% Assignment: EGR102-001 LED Current Safety Check
% Date: 09/16/2019
% Purpose: Compares the current of a circuit consisting of 3 resistors to
the max safe current of an LED and displays whether its safe or not
%}

%%
% Declare several constants to help us throughout execution
SOURCE_VOLTAGE = 5;
LED_FORWARD_VOLTAGE = 1.85;
LED_MAX_CURRENT = 30;

%%

%%
% Take input for the three resistors, if the user inputs a negative value
% then correct it
resistorOneOhms = input("Resistance of Resistor1: ");
if (resistorOneOhms < 0)
   fprintf("Negative resistance, reversing.")
   resistorOneOhms = -resistorOneOhms;
end

resistorTwoOhms = input("Resistance of Resistor2: ");
if (resistorOneOhms < 0)
   fprintf("Negative resistance, reversing.")
   resistorTwoOhms = -resistorTwoOhms;
end

resistorThreeOhms = input("Resistance of Resistor3: ");
if (resistorOneOhms < 0)
   fprintf("Negative resistance, reversing.")
   resistorThreeOhms = -resistorThreeOhms;
end
%%

%%
% Computer the effective resistance formula using the effective resistance
% formula
effectiveResistance = 1/((1/resistorOneOhms) + (1/resistorTwoOhms) + (1/resistorThreeOhms));
current = LEDcurrent(SOURCE_VOLTAGE, LED_FORWARD_VOLTAGE, effectiveResistance);
currentInMilliamps = current * 1000; % Convert amp-based current to milliamps
%%

%%
% OUTPUT the result to the user
if (currentInMilliamps > LED_MAX_CURRENT)
    fprintf("WARNING: Unsafe current.\n%.2f", currentInMilliamps);
else
    fprintf("Current is safe.\n%.2f", currentInMilliamps);
end
%%