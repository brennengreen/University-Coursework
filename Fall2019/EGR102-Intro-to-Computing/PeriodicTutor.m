%{
% Author: Brennen Green
% Assignment: EGR102-001 Periodic Tutor
% Date: 10/28/2019
% Purpose: A command line interface to help the user study the periodic
table
%}

% Impor the data from the xls file as text day then read the data into a
% specific identifier dependent on if its a elementName or symbol
[~, data, ~] = xlsread("periodicTable.xlsx");
elementNames = data(:, 1);
elementSymbols = data(:, 2);
[numElements, ~] = size(elementNames); % User the number of element games to give the num elements;


%% Display logo to the user
disp("//---------------------------------\\")
disp("||         PERIODIC TUTOR          ||")
disp("||          BRENNEN GREEN          ||")
disp("\\---------------------------------//")
%%
%% Execution loop
numToReview = input("How many elements do you want to review: "); % Get number of elements from user
reviewedElements = zeros(numToReview); % Allocate array space to review specific num of elements
numCorrectSymbols = 0;
numCorrectNumbers = 0;
for i = 1:numToReview % Loop through the number of elements user chose to review
    atomicNumber = randi(numElements);
    eleName = elementNames{atomicNumber};
    eleSymbol = elementSymbols{atomicNumber};
    reviewedElements(i) = atomicNumber;
    
    fprintf("Current Element: %s\n", eleName);
    
    % If user guessed correct symbol, show message and increment number 
    symbolGuess = input("Element Symbol: ", 's');
    if (symbolGuess(1:2) == eleSymbol)
        fprintf("Congratulations\n");
        numCorrectSymbols = numCorrectSymbols + 1;
    else
        fprintf("Sorry! The correct symbol is: %s\n", eleSymbol);
    end
    
    % If user guessed correct atomic number, show message and increment
    % number
    atomicGuess = input("Element's Atomic Number: ");
    if (atomicGuess == atomicNumber)
        fprintf("Congratulations\n");
        numCorrectNumbers = numCorrectNumbers + 1;
    else
        fprintf("Sorry! The correct atomic number is: %d\n", atomicNumber);
    end
    pause(0.5); % Pause for pacing
end
reviewedElements = reviewedElements';
%%

%% Prepare to end program with a summary report
if (numToReview <= 0)
   disp("No elements were reviewed"); 
else
    fprintf("//-------------------------------------------\\\\ \n")
    fprintf("|| SESSION REVIEW                            || \n")
    fprintf("||-------------------------------------------|| \n")
    fprintf("|| Number of Elements Reviewed:   %03d        || \n", numToReview)
    fprintf("|| Correct Element Symbols:       %03d (%3.1f%%)|| \n", numCorrectSymbols, (numCorrectSymbols/numToReview)*100)
    fprintf("|| Correct Atomic Numbers:        %03d (%3.1f%%)|| \n", numCorrectNumbers, (numCorrectNumbers/numToReview)*100)
    fprintf("||-------------------------------------------|| \n")
    fprintf("|| REVIEWED ELEMENTS                         || \n")
    fprintf("||-------------------------------------------|| \n")
    for i = 1:numToReview
        fprintf("|| %03d %-15s                       ||\n", reviewedElements(1, i), elementNames{reviewedElements(1, i)}) 
    end
    fprintf("\\\\-------------------------------------------//\n")

end
disp("Thank you for using The Periodic Tutor!");
%%
% End of Program