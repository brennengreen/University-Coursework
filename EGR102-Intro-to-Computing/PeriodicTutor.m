[~, ~, data] = xlsread("periodicTable.xlsx");
elementNames = data(:, 1);
elementSymbols = data(:, 2);
[numElements, ~] = size(elementNames);


disp("+---------------------------------+")
disp("-         PERIODIC TUTOR          -")
disp("-          BRENNEN GREEN          -")
disp("+---------------------------------+")

numToReview = input("How many elements do you want to review: ");
reviewedElements = zeros(numToReview);
numCorrectSymbols = 0;
numCorrectNumbers = 0;
for i = 1:numToReview
    atomicNumber = randi(numElements);
    eleName = elementNames{atomicNumber};
    eleSymbol = elementSymbols{atomicNumber};
    reviewedElements(i) = atomicNumber;
    
    fprintf("Current Element: %s\n", eleName);
    
    symbolGuess = input("Element Symbol: ");
    if (symbolGuess == eleSymbol)
        fprintf("Congratulations\n");
        numCorrectSymbol = numCorrectSymbol + 1;
    else
        fprintf("Sorry! The correct symbol is: %s\n", eleSymbol);
    end
    
    atomicGuess = input("Element's Atomic Number: ");
    if (atomicGuess == atomicNumber)
        fprintf("Congratulations\n");
        numCorrectAtomic = numCorrectAtomic + 1;
    else
        fprintf("Sorry! The correct atomic number is: %s\n", atomicNumber);
    end
    pause(0.5);
end





fprintf("%s, %s\n",eleName, eleSymbol);
if (symbolGuess == eleSymbol)
    fprintf("Congratulations\n");
    numCorrectSymbol = numCorrectSymbol + 1;
else
    fprintf("Sorry! The correct symbol is: %s\n", eleSymbol);
end
if (atomicGuess == atomicNumber)
    fprintf("Congratulations\n");
    numCorrectAtomic = numCorrectAtomic + 1;
else
    fprintf("Sorry! The correct atomic number is: %s\n", atomicNumber);
end
