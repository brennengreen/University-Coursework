% Create variables for the source voltage (5V), LED forward voltage (1.85V), and the LED maximum current (30 milliamps).
% Input the value of the first resistor.
% If the value is negative:
% Print Negative resistance, reversing.
% Set the resistor's value to its negation (for example - resistance = -resistance
% Repeat steps 2 and 3 for the other two resistors.
% Calculate the effective resistance using the parallel resistor formula. 
% Calculate the current through a function based on the two voltages and the effective (total) resistance.  
% Convert the current to milliamps by multiplying by 1000.
% If the current in milliamps is greater than the diode's maximum current rating:
% Display the message WARNING: Unsafe current.
% Otherwise,
% Display the message Current is safe.
% % Display the current in milliamps.

SOURCE_VOLTAGE = 5;
LED_FORWARD_VOLTAGE = 1.85;
LED_MAX_CURRENT = 30;

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

effectiveResistance = 1/((1/resistorOneOhms) + (1/resistorTwoOhms) + (1/resistorThreeOhms));
current = LEDcurrent(SOURCE_VOLTAGE, LED_FORWARD_VOLTAGE, effectiveResistance);
currentInMilliamps = current * 1000;

if (currentInMilliamps > LED_MAX_CURRENT)
    fprintf("WARNING: Unsafe current.\n%.2f", currentInMilliamps);
else
    fprintf("Current is safe.\n%.2f", currentInMilliamps);
end