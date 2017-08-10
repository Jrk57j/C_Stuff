#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void sys_err(char *msg){
  perror(msg);
  exit(-1);
}

int main(int argc, char *argv[]){
  int i,fd[2];

  pipe(fd);
  switch(fork()){
    case -1:
    sys_err("fork error");
    break;
    case 0:
    dup2(fd[0],STDIN_FILENO);
    close(fd[0]);
    close(fd[1]);
    execlp("ps","ps","aux",NULL);
    sys_err("exec error");
    break;
    defualt:
    dup2(fd[1],STDOUT_FILENO);
    close(fd[1]);
    close(fd[0]);
    execlp("grep","grep","julain",NULL);
    sys_err("exec error");
    break;
  }
  exit(0);
}
