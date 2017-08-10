#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define BLK 1024

void sys_err(char *msg){
  perror(msg);
  exit(-1);
}
int main(int argc, char *argv[]){
  int fin,fout,n;
  char buf[1024];
  if((fin = open(argv[1],O_RDONLY))<0){
    sys_err("open error");
  }
  fout = open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0644);
  if(fout<0){
    sys_err("fout error");
  }
  // while((n = read(fin, buf, BLK))>0){
  //   if((write(fout, buf,n))!=n){
  //     sys_err("write error");
  //   }
    n=read(fin,buf,BLK);
    write(fout, buf,n);
    lseek(fout, 400, SEEK_CUR);
    write(fout,buf,n);
  //}

  exit(0);
}
