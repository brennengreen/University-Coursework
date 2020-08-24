#include <stdio.h>

void test_int(int a) 
{
	if (a * a >= 0) printf("%d * %d >= 0\n", a, a); 
                   else printf("%d * %d < 0\n", a, a);
}

int main()
{
    test_int(0);
    test_int(40000);
    test_int(-35);
    test_int(50000);
}

