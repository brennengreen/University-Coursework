[~, ~, data] = xlsread("periodicTable.xlsx");
elementNames = data(:, 1);
elementSymbols = data(:, 2);
[numElements, ~] = size(elementNames);

numToReview = input("How many elements do you want to review: ");
for i = 1:numToReview
    atomicNumber = randi(numElements);
    disp(atomicNumber);
end

eleName = elementNames{atomicNumber};
eleSymbol = elementSymbols{atomicNumber};



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
