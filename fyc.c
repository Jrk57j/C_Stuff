#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define BLK 17

void sys_err(char *msg){
  perror(msg);
  exit(-1);
}

int main(int argc, char *argv[]){
  int fin, n;
  int rs = 17;
  char buf[BLK];
  char msg[] ="THIS IS THE NEW!!";

  if((fin = open(argv[1], O_RDWR))<0){
    sys_err("Fin open error");
  }
  n = lseek(fin, rs*280, SEEK_CUR);
//  lseek(fin, n, SEEK_SET);
  write(fin, msg,17);

  exit(0);
}
