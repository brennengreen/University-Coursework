%  AssembleSeqs - Combine two overlapping strings (UKY EGR 102 Week 9)
%  BY: Brennen Green
%  Returns the shortest combined string that starts with the
%  left string and ends with the right string.  Also returns the
%  number of characters of overlap.  For example:
%     AssembleSeqs('genetic', 'code') => [ 'geneticode', 1 ]

function [combined,overlap] = AssembleSeqs(left,right)
    combined = strcat(left, right);
    overlap = 0;
    
    shortStr = min(length(left), length(right));
    
    for i=1:shortStr
        leftPart = left(end - i + 1:end);
        rightPart = right(1:i);
        if (strcmpi(leftPart, rightPart) == 1)
           overlap = i;
           combined = strcat(left, right(i+1: end));
        end
    end

end

