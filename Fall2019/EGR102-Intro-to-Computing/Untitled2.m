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
r = 0.5;

for i=r:0.2:2
    timePoints = (0:1/12:10);
    numPoints = length(timePoints);
    populations = zeros(1, numPoints);

    for j = 1:numPoints
       t = timePoints(j);
       exp_growth = P * exp(r * t);
       populations(j) = (K * exp_growth) / (K + exp_growth - P);
    end
    hold on
    plot(timePoints, populations);
    hold off
    r = i;
end
 title('Logistic growth curve');
xlabel('Time (years)');
ylabel('Populations');
    
