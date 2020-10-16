#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 4

/* Set Abuf to be empty.  Read string into Bbuf. Print out Abuf and Bbuf */
void echo() {
	char Abuf[BUFLEN];
	char Bbuf[BUFLEN];
	Abuf[0] = '\0';
	gets(Bbuf);
	printf(" Abuf = '%s'\n Bbuf = '%s'\n", Abuf, Bbuf);
} // echo()

int main() {
	printf("Enter a string: ");
	echo();
	return(0);
} // main()
