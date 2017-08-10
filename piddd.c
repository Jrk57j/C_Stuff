#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void sys_err(char *msg){
  perror(msg);
  exit(-1);
}

int main(void){
  int fd[23][2], i, dexrim ;
  pid_t child;
  pid_t parent;
  char msg[] = " messages are accounted for";//29
  //creates 2 pipes
  for(i =0; i < 3; i++){
    if(pipe(fd) == -1){
      sys_err("call mario, pipe is broken");
    }
  }

  for(i = 1; 1 < 23; i++){
    switch(parent = fork()){
      case -1:
      sys_err("get a spoon");
      case 0:
      dex = i;//index assignment for the proc
      break;
      default:
      wait(NULL);
      exit(0);
    }
  }
  child = getpid();
  sprintf(msf, %d, ndex);
  if(parent){

  }
  }

}
