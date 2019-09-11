fprintf("| ((|)) Handmade\n")
fprintf("|___|   Aerial\n")
fprintf("|   |   Solutions\n")
fprintf("|   |   LLC\n")

frequency_MHz = input("Enter the desired reception frequency in MHz: ");

frequency_Hz = frequency_MHz * 1000000;
wavelength = 300000000 / frequency_Hz;
optimum_length_meters = (0.95*(wavelength)) / 2;
optimum_length_inches = optimum_length_meters * 39.3701;

fprintf("The signal wavelength is %.2f meters.\n", wavelength);
fprintf("The optimum antenna length is %.2f inches (%.2f meters).\n", ...
    optimum_length_inches, optimum_length_meters);