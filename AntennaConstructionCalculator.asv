%{
% Author: Brennen Green
% Assignment: EGR102-001 Optimum Antenna Length Calculator
% Date: 09/10/2019
% Purpose: Given an input of frequency in MHz, calculate and display
optimum length of antenna.
%}

% Display HASL Logo
fprintf("| ((|)) Handmade\n")
fprintf("|___|   Aerial\n")
fprintf("|   |   Solutions\n")
fprintf("|   |   LLC\n")

% Get input from the user for the frequency in MHz
frequency_MHz = input("Enter the desired reception frequency in MHz: ");

% Perform the computations necessary to convert the input units to the desired
% units for the output. 
% Calculate optimum length of antenna
frequency_Hz = frequency_MHz * 1000000;
wavelength = 300000000 / frequency_Hz;
optimum_length_meters = (0.95*(wavelength)) / 2;
optimum_length_inches = optimum_length_meters * 39.3701; % Convert to inches

% Output the previously calculated values to the user in a nice, pretty
% formatted form
fprintf("The signal wavelength is %.2f meters.\n", wavelength);
fprintf("The optimum antenna length is %.2f inches (%.2f meters).\n", ...
    optimum_length_inches, optimum_length_meters);