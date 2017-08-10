#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void sys_err(char *msg){
  perror(msg);
  exit(-1);
}

int main(void){


}
