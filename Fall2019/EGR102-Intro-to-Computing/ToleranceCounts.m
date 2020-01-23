NOMINAL_WEIGHT_IN_OZ = 4.13;
TOLERANCE_IN_OZ = 0.25;
MAX_IN_OZ = (NOMINAL_WEIGHT_IN_OZ + TOLERANCE_IN_OZ);
MIN_IN_OZ = (NOMINAL_WEIGHT_IN_OZ - TOLERANCE_IN_OZ);

measured_weights = xlsread("MnMTolerances.xlsx");
num_of_weights = length(measured_weights);

fprintf("First Weight: %.2f Last Weight: %.2f \n", measured_weights(1), measured_weights(num_of_weights));

overweight_values = measured_weights > MAX_IN_OZ;
numOverWeight = sum(overweight_values);
percentOverWeight =((numOverWeight / num_of_weights) * 100.0);

underweight_values = measured_weights < MIN_IN_OZ;
numUnderWeight = sum(underweight_values);
percentUnderWeight =((numUnderWeight / num_of_weights) * 100.0);


fprintf("Underweight (< %.2f) items: %d (%.2f%%)\n", MIN_IN_OZ, numUnderWeight, percentUnderWeight);
fprintf("Overweight (> %.2f) items: %d (%.2f%%)\n", MAX_IN_OZ, numOverWeight, percentOverWeight);


