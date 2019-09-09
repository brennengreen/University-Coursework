%{
% Author: Brennen Green
% Assignment: EGR102-001 Parallel Resistance Calculator
% Date: 09/03/2019
% Purpose: Calculate the total resistance of a circuit
% containing three resistors in parallel
%}

% Indivisual variables for the resistance of each resistor in the circuit
resistor_1 = input("Enter the resistance for resistor one: ");
resistor_2 = input("Enter the resistance for resistor two: ");
resistor_3 = input("Enter the resistance for resistor three: ");

% Calculate the total resistance of the circuit using the equation
% 1 / (1/R1 + 1/R2 + 1/R3)
total_resistance = 1/((1/resistor_1) + (1/resistor_3) + (1/resistor_2));

% Separate the output from the input using a hyphen divider 
% Then output the formatted string for the resistance
disp("-------------------------------------------------------------------")
fprintf("For the parallel circuit of:\nR1: %dOhm R2: %dOhm R3: %dOhm\nTotal Resistance:%.2f\n", ...
    resistor_1, resistor_2, resistor_3, total_resistance)
disp("-------------------------------------------------------------------")