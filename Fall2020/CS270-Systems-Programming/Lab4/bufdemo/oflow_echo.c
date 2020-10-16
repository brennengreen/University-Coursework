#include <stdlib.h>
#include <stdio.h>

#define BUFLEN 4 /* much too small */

void echo();

/* Main program */
int main() {
	while (1) { // keep echoing input
		echo();
	}
	return(0); // never called
} // main

/* My gets, like gets: Get a string from stdin */
char *mygets(char *dest) {
	int c = getchar();
	char *p = dest;
	while (c != EOF && c != '\n') {
		*p++ = c;
		c = getchar();
	}
	*p = '\0';
	return dest;
} // mygets

/* Echo Line */
void echo() {
	char buf[BUFLEN];
	mygets(buf);
	puts(buf);
} // echo
  
void not_called() {
	printf("This routine is never called, but you managed to call it.\n");
	printf("Congratulations!\n");
	exit(0);
} // not_called
