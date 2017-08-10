#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void sys_err(char *msg){
  perror(msg);
  exit(-1);
}

struct proc{
  pid_t pid;
  int cnt;
  int bytes;
}msg;

int main(void){
  int ppipe[2], cpipe[2], cnt, i, parent, dex, pid;
int n;
  if(pipe(ppipe)||pipe(cpipe)){
    sys_err("call mario");
  }
  for(i = 1; i <= 11; i++){
    switch(parent = fork()){
      case -1:
      sys_err("switch err");
      case 0:
      dex = i;
      break;
      default:
    if(parent){
      break;
    }
    }
  }
  pid = getpid();
  if(dex == 0){
    for(i = 1; i <= 1000; i++){
      write(cpipe[1], &i, sizeof(int));
      close(cpipe[1]);
      while((n = read(ppipe[0], &msg, sizeof(msg)))>0){
        printf("child %d read ints %d\n", msg.pid, msg.cnt);
        close(ppipe[0]);
      }
    }
  }else{
    close(ppipe[0]);
    close(cpipe[1]);
    msg.pid = getpid();
    msg.cnt = 0;
    while((n = read(cpipe[0], &i, sizeof(int)))>0){
      msg.cnt++;
    }
    close(cpipe[0]);
    write(ppipe[1], &msg, sizeof(msg));
    close(ppipe[1]);
  }
  exit(0);
}
