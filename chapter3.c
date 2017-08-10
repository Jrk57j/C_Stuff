#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void sys_err(char *msg){
  perror(msg);
  exit(-1);
}

int main(void){
  // int p;
  // printf("My pid is: %d \n", getpid());
  // printf("My ppid is: %d \n", getppid());
  // printf("My uid is: %d\n", getuid());
  // printf("My euid should be the same as  my uid...%d\n",geteuid());

//  printf("--------------------------------------------------\n\n");
  int i, n = 5;
  for(i = 1; i < n; i++){
  switch(fork()){
    case -1:
    sys_err("fork error");
    break;
    case 0: //child case
  //  printf("My pid is %d and my ppid is %d\n", getpid(), getppid());
    break;
    default://parent process to the child
    wait(3);
    //printf("This is default\n");
    //printf("My ppid is: %d\n", getppid());
    //printf("And my pid is: %d\n", getpid());
  }
}  if((getppid()%2)==0){
    printf("my ppid even and my pid is: %d and my ppid is: %d\n", getpid(), getppid());
  }else{
    printf("my ppid odd and my pid is: %d and my ppid is: %d\n", getpid(), getppid());
  }
//}
  exit(0);
}
