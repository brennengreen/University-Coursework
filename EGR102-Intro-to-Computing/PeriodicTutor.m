[~, ~, data] = xlsread("periodicTable.xlsx");
elementNames = data(:, 1);
elementSymbols = data(:, 2);
[numElements, ~] = size(elementNames);


disp("+---------------------------------+")
disp("-         PERIODIC TUTOR          -")
disp("-          BRENNEN GREEN          -")
disp("+---------------------------------+")

numToReview = input("How many elements do you want to review: ");
reviewedElements = [];
numCorrectSymbols = 0;
numCorrectNumbers = 0;
for i = 1:numToReview
    atomicNumber = randi(numElements);
    eleName = elementNames{atomicNumber};
    eleSymbol = elementSymbols{atomicNumber};
    reviewedElements(i) = atomicNumber;
    
    fprintf("Current Element: %s\n", eleName);
    
    symbolGuess = input("Element Symbol: ", 's');
    if (symbolGuess == eleSymbol)
        fprintf("Congratulations\n");
        numCorrectSymbols = numCorrectSymbols + 1;
    else
        fprintf("Sorry! The correct symbol is: %s\n", eleSymbol);
    end
    
    atomicGuess = input("Element's Atomic Number: ");
    if (atomicGuess == atomicNumber)
        fprintf("Congratulations\n");
        numCorrectNumbers = numCorrectNumbers + 1;
    else
        fprintf("Sorry! The correct atomic number is: %d\n", atomicNumber);
    end
    pause(0.5);
end
reviewedElements = reviewedElements';

if (numToReview <= 0)
   disp("No elements were reviewed"); 
else
    fprintf("//-------------------------------------------\\\\ \n")
    fprintf("|| SESSION REVIEW                            || \n")
    fprintf("||-------------------------------------------|| \n")
    fprintf("|| Number of Elements Reviewed:   %d         || \n", numToReview)
    fprintf("|| Correct Element Symbols:       %d (%4.1f%%) || \n", numCorrectSymbols, (numCorrectSymbols/numToReview)*100)
    fprintf("|| Correct Atomic Numbers:        %d (%4.1f%%) || \n", numCorrectNumbers, (numCorrectNumbers/numToReview)*100)
    fprintf("||-------------------------------------------|| \n")
    fprintf("|| REVIEWED ELEMENTS                         || \n")
    fprintf("||-------------------------------------------|| \n")
    for i = 1:numToReview
        fprintf("|| %d %s                                     ||\n", reviewedElements(i), elementNames(reviewedElements(i))) 
    end
    fprintf("\\\\-------------------------------------------//\n")
    
    
    
    
    
    
    
    
end
