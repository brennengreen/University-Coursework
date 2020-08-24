#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a[2];
  double d;
} struct_t;

double fun(int i) {
  volatile struct_t s;
  s.d = 3.14;
  s.a[i] = 1073741824; /* Possibly out of bounds */
  return s.d;
}

int main(int argc, char **argv)
{
  int x;
  if (argc != 2) {printf("Usage: %s number\n", argv[0]);
                  exit(1);
                 }
  x = atoi(argv[1]);
  printf("fun(%d) = %lf\n", x, fun(x));
}

