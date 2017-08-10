#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void sys_err(char *msg){
  perror(msg);
  exit(-1);
}

int main(int argc, char *argv[]){
  pid_t cpid = 0;
  int i, n;
  if(argc != 2){
    sys_err("Not enough args");
  }

  n = atoi(argv[1]);
  for(i =1; i < n; i++){
    if((cpid = fork())<= 0){
      fprintf(stderr, "i: %d process ID: %d parent id: %d child id: %d\n"
      , i, getpid(), getppid(), cpid);
    }
  }
exit(0);
}
