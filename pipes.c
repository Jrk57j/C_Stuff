#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void sys_err(char *msg){
  perror(msg);
  exit(-1);
}

int main(void){
  int  n, i, fd[2],ndx=0;
  int child;
  int parent;
  char mess[40];

  pipe(fd);
  for(i = 1; i < 10; i++){
    parent = getpid();
    switch(parent = fork()){
      case -1:
      sys_err("fork error");
      break;
      case 0:
      ndx = i;
      break;
      if(parent == 0){
        break;
      }

    }child = getpid();
    sprintf(mess, "%d\t%d",getpid(), ndx);

    if((child%2)==0){
    printf(" something even %s\n", mess);
  }else{
    printf("something odd %s\n", mess);
  }
}
exit(0);
}
