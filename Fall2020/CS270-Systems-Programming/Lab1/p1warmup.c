#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char oneline[1024];
	int len, i, val;
	char *p;

	if (fgets(oneline, 1024, stdin) == NULL) { // NULL indicates the end of a file
		printf("End of File!\n");
	}
	else {
		len = strlen(oneline) - 1;  // remove the newline at the end 
		i = 0;
		while ((i<len) && (oneline[i]==' ')) i++; //skip the leading space 
		if (i>=len) printf("End of the line!\n");  // reach the end of the line
		else {
			p = &(oneline[i]); // p points to the first non-space character
			sscanf(p, "%x", &val);  // read a hexadecimal number 
			printf("The decimal value of val is %d\n", val);
			printf("The character corresponding to val is %c\n", val);
		}
	}
} 
