#include <stdio.h>

void test_float(float x, float y, float z) 
{
	float sum1, sum2;

        sum1 = x + y;  sum1 = sum1 + z;
        sum2 = y + z;  sum2 = sum2 + x;
        if (sum1 == sum2) printf("They are equal!\n");
                    else  printf("They are not equal!\n");
}

int main()
{
    test_float(1.0, 2.0, 3.0);
    test_float(1.0, -2.0, 3.0);
    test_float(1e20, -1e20, 3.0); 
}

