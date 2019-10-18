function [numCorrectSymbol, numCorrectAtomic] = PeriodicTutor (atomicNumber, symbolGuess, atomicGuess, numCorrectSymbol, numCorrectAtomic)
    [~, ~, data] = xlsread("periodicTable.xlsx");
    elementNames = data(:, 1);
    elementSymbols = data(:, 2);
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
end