#include <stdio.h>
#include <unistd.h>

int main() {

  int x = 1;
  pid_t pid;
  
  pid = fork();
  printf("pid=%d\n", pid);

  if (pid ==0) {
    printf("Child Process ID %d\n", getpid());
    x++;
    printf("%d", x);
    printf("hello from child\n");
  }
  else {
    printf("(Parent) Child PID: 0\n");
    x--;
    printf("%d", x);
    printf("hello from parent\n");
  }
  return(0);
} // main()
