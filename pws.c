#include <stdlib.c>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void sys_err(char *msg){
  perror(msg);
  exit(-1);
}

struct pro{
  int index;
  pid_t pid;
}p;

int main(void){
  int fd[10][2],i, n, pid;
  struct pro p;

  if(pipe(fd)==-1){
    sys_err("pipe creation failed");
  }
  //going to create 10 processes dont want to start at parent
  for(i =1; i < 11; i++){
    switch(fork()){
      case -1:
      sys_err("fork error");
      break;
      case 0:
      p.index = i;
      break;
      default:
      wait(NULL);
    }
    p.pid = getpid();
    if(p.index == 1){
      close(fd[0][1]);//dont want to write to ourselves
    }
    if((p.pid%2)==0){
      //write out
      write(fd[i][1], p.pid+" "+p.index, 20);
    }else{
      write(fd[i][1],p.pid+" "+p.index, 20);
    }
    }
  }
}
