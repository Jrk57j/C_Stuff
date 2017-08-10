#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void sys_err(char *msg){
  perror(msg);
  exit(-1);
}
struct proc{
  pid_t child;
  pid_t parent;
  int index;
};
int main(void){
  int i, n = 5;
  struct proc p;
  for(i = 1; i < n; i++){
    switch(fork()){
      case -1:
      sys_err("fork error");
      break;
      case 0:
      p.index = i;
        break;
      if(p.parent == 0){
        break;
      }
    }
  }
  for(i = 0; i < n; i++){
    p.child = getpid();
    p.parent = getppid();
    if((p.child %2)==0){
        printf("my ppid is even and my pid is: %d and my ppid is: %d...index: %d\n", p.child, p.parent, p.index);
      }else{
        printf("my ppid is odd and my pid is: %d and my ppid is: %d....index: %d\n", p.child, p.parent, p.index);
      }
    }
  exit(0);
}
