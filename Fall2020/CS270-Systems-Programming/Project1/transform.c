#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int skipWhitespace(int * iterator, char thisLine[1024]);
void eatToken(int * iterator, char thisLine[1024]); 
void processLiteral(char * token);
void processHex(char * token);
void processDecimal(char * token);

int main(int argc, char** argv)
{
	char oneline[1024];
	int i;
	if (fgets(oneline, 1024, stdin) == NULL) { // NULL indicates the end of a file
		printf("End of File!\n");
	}
	else {
		i = 0;
		while (skipWhitespace(&i, oneline)) {
			eatToken(&i, oneline);
		}
		printf("End of line!\n");
	}
} 

void eatToken(int * iterator, char thisLine[1024]) {
	int len = strlen(thisLine) - 1;
	char * token;
	token = calloc(1024, sizeof(char));
	int i = 0;
	while (((*iterator)< len) && (thisLine[(*iterator)] != ' ')) {
		*(token + i) = thisLine[(*iterator)];
		i++;
		(*iterator)++;
	}

	if (*token == '\"') processLiteral(token);
	else if (*token == '0' && ( *(token + 1) == 'x' || *(token + 1) == 'x' )) processHex(token);
	else processDecimal(token);

	free(token);
}

void processLiteral(char * token) {
	printf("Literal: ");
	for ( int i = 0; i < strlen(token); i++) {
		printf("%c", *(token+i));
	}
	printf("\n");
}


void processDecimal(char * token) {
	printf("Decimal: ");
	for ( int i = 0; i < strlen(token); i++) {
		printf("%c", *(token+i));
	}
	printf("\n");

}

void processHex(char * token) {
	printf("Hex: ");
	for ( int i = 0; i < strlen(token); i++) {
		printf("%c", *(token+i));
	}
	printf("\n");
	int val;
	sscanf((token + 0), "%x", &val);  // read a hexadecimal number 
	printf("Decimal:%d Alphanumeric: %c\n", val, val);

}

int skipWhitespace(int * iterator, char thisLine[1024]) {
	int len = strlen(thisLine) - 1;
	while (((*iterator)<=len) && (thisLine[(*iterator)]==' ')) (*iterator)++; //skip the leading space 
	if ((*iterator) <= 90) {
		return 1;
	} else {
		return 0;
	}
}