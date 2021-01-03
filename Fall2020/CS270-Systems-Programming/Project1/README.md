# transform.c

A simple command line program that can interpret Hexadecimal/Decimal numbers as ASCII characters and output them onto the command line as such.

## Implementation

This implementation strives to act like a tokenizer, by tokenizing a line into several small chunks of information its a lot easier to process each individual token

## Struggles and Limitations

The biggest limitation of this is the lack of scalability, currently it only process a small set of tokens, as defined by the assignment guidelines. 

The struggles were mostly in making sure that the tokenizer only ate just the right amount of information and nothing else. Straggling new line characters or spaces would
cause erroneous output so it was very important to eliminate all possibility of that