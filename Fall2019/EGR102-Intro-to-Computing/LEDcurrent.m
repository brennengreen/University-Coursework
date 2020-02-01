function [currentInAmps] = LEDcurrent(sourceVoltage, ledVoltageDrop, resistanceOhms)
% This function takes in a sourceVoltage, Voltage Drop across an LED,
% and the resistance in ohms. 
% It will use this information to calculate the voltage drop across a
% resistor and output the current across the LED

    resistorVoltageDrop = sourceVoltage - ledVoltageDrop;
    currentInAmps = (resistorVoltageDrop / resistanceOhms);
end


