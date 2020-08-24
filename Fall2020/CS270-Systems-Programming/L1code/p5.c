#include <stdio.h>
#include <stdlib.h>

int arr1[2048][2048];
int arr2[2048][2048];

void copyij(int src[2048][2048],
            int dst[2048][2048])
{
  int i,j;
  for (i = 0; i < 2048; i++)
    for (j = 0; j < 2048; j++)
      dst[i][j] = src[i][j];
}


void copyji(int src[2048][2048],
            int dst[2048][2048])
{
  int i,j;
  for (j = 0; j < 2048; j++)
    for (i = 0; i < 2048; i++)
      dst[i][j] = src[i][j];
}

int main(int argc, char **argv)
{
  int x;
  int j;
  if (argc != 2) {printf("Usage: %s number\n", argv[0]);
                  exit(1);
                 }
  x = atoi(argv[1]);
  for (j=0; j<1000; j++) {
      if (x == 0) copyij(arr1, arr2);
            else  copyji(arr1, arr2);
  }
}

