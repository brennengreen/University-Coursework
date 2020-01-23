% FitData.m - Demonstrate curve-fitting
% 
% FitData.m : Fit a spreadsheet of voltage readings and temperatures
%  using both linear and quadratic curves.


data = xlsread('FitData.xlsx');
volts = data(:, 1); % Voltage readingss in column A
temps = data(:, 2); % Fahrenheit temperatures in column B

% Draw the points as a scatter plot
scatter(volts, temps);
title('Curve fitting demo');
xlabel('Voltage (V)');
ylabel('Temperature (degrees F)');

% We still have a few more things to plot.
hold on;

% Find the line of best fit for converting voltage to temperature.
% poly1 means a polynomial curve of degree 1: a line
% Returns a curve-fitting model that can be used like a function.
lineFit = fit(volts, temps, 'poly1');

% Test the fit over the voltage range 1.0 to 4.0
testV = 1.0 : 0.1 : 4.0;

% Plot the estimated temperatures for the test voltages.  lineFit(testV)
% means apply the 
plot(testV, lineFit(testV));

% Find a quadratic (degree 2) approximation for converting voltage to
% temperature, and plot it.
quadFit = fit(volts, temps, 'poly2');
plot(testV, quadFit(testV));

% Set legends for the points and curves, in order.
legend('Measured temperatures', 'Linear fit curve', 'Quadratic fit curve');

% If we plot again, erase the old plot.
hold off;

% Display information about the calculated fitting curves.
disp('****');
disp(lineFit);
disp('****');
disp(quadFit);