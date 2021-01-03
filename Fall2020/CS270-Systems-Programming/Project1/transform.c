#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// CONSTANTS
int MAX_LINE_LENGTH = 1024;


// PROTOTYPES -- Documentation Attached To Implementation
void skipWhitespace(int * iterator, char thisLine[MAX_LINE_LENGTH]);
void eatToken(int * iterator, char thisLine[MAX_LINE_LENGTH]); 
void processLiteral(char * token);
void processHex(char * token);
void processDecimal(char * token);
void processBadToken(char * token);


/*
	Function: main
	Purpose: Control main flow of program, iterate over each line of stdin
	Params:
		argc: number of arguments supplied at command line
		argv: array of arguments
*/
int main(int argc, char** argv)
{
	char oneline[MAX_LINE_LENGTH]; // Allocate space for a line of max width
	int i = 0;
	while (fgets(oneline, MAX_LINE_LENGTH, stdin) != NULL) { // Gather each line of input from stdin one at a time
		while (i < strlen(oneline) - 1) {
			skipWhitespace(&i, oneline); // skip whitespace up to the next token
			if (oneline[i] == '/' || oneline[i] == '\n') break; // Token is a comment or a newline character
			eatToken(&i, oneline); // eat (process) the next token
		} 
		i = 0; // reset line iterator
	}
} 

/* 
	Function: eatToken
	Purpose: Called whenever a non-trivial character is found to process the token type
	Params:
		iterator: pointer to the iterator for the current line
		thisLine: copy of the current line to eat a token from
*/
void eatToken(int * iterator, char thisLine[MAX_LINE_LENGTH]) {
	int len = strlen(thisLine);
	char * token;
	token = calloc(len, sizeof(char)); // Allocate enough memory to be able to process a token of large length
	int i = 0;
	// While the iterator does not exceed bounds, and there is another non trivial character to eat, add that char to the current token
	if (thisLine[*iterator] == '\"') { // Case where the token is a literal (string)
		(*iterator)++;
		while (((*iterator)<= len) && (thisLine[(*iterator)] != '\"')) {
			*(token + i) = thisLine[(*iterator)];
			i++;
			(*iterator)++;
		}
		(*iterator)++;
		processLiteral(token);
	} else { // Any other type of token besides a literal
		while (((*iterator)<= len) && thisLine[(*iterator)] != ' ') {
			if (thisLine[(*iterator)] == '\n') // Avoid possibly eating a trailing newline character
			{
				i++;
				(*iterator)++;
				continue;
			}
			else {
				*(token + i) = thisLine[(*iterator)];
				i++;
				(*iterator)++;
			}
		}
		if (*token == '0' && ( *(token + 1) == 'X' || *(token + 1) == 'x' )) processHex(token);
		else if (isdigit(*token)) processDecimal(token);
		else processBadToken(token);
	}
	free(token);
}


/* 
	Function: processLiteral
	Purpose: Called to process a literal token
	Params:
		token: pointer to the current token being processed
*/
void processLiteral(char * token) {
	for ( int i = 0; i < strlen(token); i++) {
		printf("%c", *(token+i));
	}
}

/* 
	Function: processDecimal
	Purpose: Called to process a decimal token
	Params:
		token: pointer to the current token being processed
*/
void processDecimal(char * token) {
	int val;
	sscanf((token + 0), "%d", &val);
	if (val > 255) { // Process bad tokens that are out of range
		printf("OUT_OF_RANGE_TOKEN[%d]", val);
		exit(1);
	}
	printf("%c", val);
}

/* 
	Function: processHex
	Purpose: Called to process a hexadecimal token
	Params:
		token: pointer to the current token being processed
*/
void processHex(char * token) {
	int val;
	sscanf((token + 0), "%x", &val);  // read a hexadecimal number 
	if (val > 255) { // Process bad tokens that are out of range
		printf("OUT_OF_RANGE_TOKEN[%d]", val);
		exit(1);
	}
	printf("%c", val);

}

/* 
	Function: processBadToken
	Purpose: Called to process a malformed token
	Params:
		token: pointer to the current token being processed
*/
void processBadToken(char * token) {
	if (strlen(token) < 1) return;
	printf("MALFORMED_TOKEN[%s]", token);
	exit(1);
}

/* 
	Function: skipWhitespace
	Purpose: Called to skip all trivial white space up to the start of the next token
	Params:
		iterator: pointer to the iterator for the current line
		thisLine: copy of the current line to eat a token from
*/
void skipWhitespace(int * iterator, char thisLine[MAX_LINE_LENGTH]) {
	int len = strlen(thisLine);
	while (((*iterator)<=len) && (thisLine[(*iterator)]==' ')) (*iterator)++; //skip the leading space 
}