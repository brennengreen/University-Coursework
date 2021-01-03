/*
 * calc.c - a minimal CGI program that performs calculator functions
 */
/* $begin adder */
#include "csapp.h"

int main(void) {
    char *buf;//, *p;
    char arg1[MAXLINE], arg2[MAXLINE], op[MAXLINE], content[MAXLINE]; // The four "valuable" tokens we need to parse from the string
    int n1=0, n2=0, result=0; // THe numerical results

    /* Extract the arguments */
    if ((buf = getenv("QUERY_STRING")) != NULL) { // Check if the QUERY_STRING exists
        buf = strtok(buf, "&="); // Tokenize the QUERY_STRING
        // Using a specific while loop to catch the valuable tokens just in case order changes
        while (buf != NULL) {
            if(strcmp(buf, "op") == 0) { // Found operation token
                buf = strtok(NULL, "&="); // Skip identifier token
                strcpy(op, buf);
            } else if (strcmp(buf, "operand1") == 0) { // Found operand1 token
                buf = strtok(NULL, "&="); // Skip identifier token
                strcpy(arg1, buf);
                n1 = atoi(arg1); // Store as int
            } else if (strcmp(buf, "operand2") == 0) { // Found operand 2 token
                buf = strtok(NULL, "&="); // Skip identifier token
                strcpy(arg2, buf);
                n2 = atoi(arg2); // Store as int
            }
            buf = strtok(NULL, "&="); // Go to next token
        }
    }

    // Check the operation type
    if (strcmp(op, "add") == 0) { // Addition
        strcpy(op, "+");
        result = n1 + n2; // Perform the operation and store result
    } else if (strcmp(op, "subtract") == 0) { // Subtraction
        strcpy(op, "-");
        result = n1 - n2; // Perform the operation and store result
    } else if (strcmp(op, "multiply") == 0) { // Multiplication
        strcpy(op, "*");
        result = n1 * n2; // Perform the operation and store result
    }

    /* Make the response body */
    sprintf(content, "Welcome to the Calculator: ");
    sprintf(content, "%sThe answer is: %d %s %d = %d\r\n<p>", content, n1, op, n2, result); // Communicate results back to the frontend
    sprintf(content, "%sThanks for visiting!\r\n", content);
  
    /* Generate the HTTP response */
    printf("Connection: close\r\n");
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);

    exit(0);
}
/* $end adder */
