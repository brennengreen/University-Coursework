%{
% Author: Brennen Green
% Assignment: EGR103 Metal Deformation Calculator
% Date: 01/25/2020
% Purpose: Calculate the elongation of metal under force and graph the 
% comparison of various other metals
%}

% e = FL / AE
% e = elongation
% F = Force in kiloNewtons
% L = Length in meters
% A = Cross sectional area in mm^2
% E = Constant modulous of elasticity in gigapascals

length = 2.5;
cross_area = 50;
force = 5;
E_steel = 200;
E_stainless = 180;
E_titanium = 110;
E_aluminum = 68.9;

e_steel = (force * length) / (cross_area * E_steel);
e_stainless = (force * length) / (cross_area * E_stainless);
e_titanium = (force * length) / (cross_area * E_titanium);
e_aluminum = (force * length) / (cross_area * E_aluminum);

elongation = [e_steel, e_aluminum, e_stainless, e_titanium];
metalNames = ["A-36 Steel", "6061-T6 Aluminum", "AISI 302 Stainless Steel", "Titanium Alloy"];

ax = gca;
bar(elongation);
grid on;
ax.XTickLabel = metalNames;
ax.XTickLabelRotation = 30;
ylabel("Elongation (meters)");
title("Elongation of Different Materials");
