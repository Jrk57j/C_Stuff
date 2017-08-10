#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <all the stuff>

void sys_err(char *msg){
  perror(msg);
  exit(-1);
}
//niscat passwd.org_dir
//| egrep rexp where this is argv[1]
int main(int argvc, char *argv[]){
  int fd[2];
  pipe(fd);

  switch(fork()){
    case -1:
    sys_error("shits fucked");
    break;
    case 0:
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    close(fd[1]);
    execlp("niscat","niscat", "passwd.org_dir", NULL);
    sys_err("execlp fail");
    break;
    default:
    dup2(fd[1],STDIN_FILENO);
    close(fd[0]);
    close(fd[1]);
    execlp("egrep","egrep",argv[1],NULL);
    exit(0);
  }
}
