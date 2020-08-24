#include <stdio.h>

void test_int(int a) 
{
	if (a * a >= 0) printf("%d * %d >= 0\n", a, a); 
                   else printf("%d * %d < 0\n", a, a);
}
