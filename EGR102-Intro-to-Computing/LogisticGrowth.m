%{
% Author: Brennen Green
% Assignment: EGR102-001 Logistic Growth Plot
% Date: 10/15/2019
% Purpose: Plot the logistic growth function
%}

NOMINAL_WEIGHT = 4.13;
TOLERANCE = 0.25;
MAX = NOMINAL_WEIGHT + TOLERANCE;
MIN = NOMINAL_WEIGHT - TOLERANCE;

P = 50;
K = 5000;
r = 1.1;

time = (0:1/12:10);
numPoints = length(time);
populations = zeros(1, numPoints);

for i = 1:numPoints
   t = time(i);
   exp_growth = P * exp(r * t);
   populations(i) = (K * exp_growth) / (K + exp_growth - P);
end

plot(time, populations, 'r');
title('Logistic growth curve');
xlabel('Time (years)');
ylabel('Populations');

