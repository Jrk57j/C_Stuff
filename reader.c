#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BLK 1024

int main(int argc, char *argv[]){

        int fin, fout, n;
        char buf[BLK];

        /*
        if fin open has less less then 0 bytes either
        there was nothing read in or the '\0' was found
        with nothing in front of it or with no \n
        */
        //open(source, flag)
        if((fin = open(argv[1], O_RDONLY))<0){
          perror("Nothing read");
          exit(-1);
        }
        //open(destination, flags, permission(0644))
        //fout = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT,0644);
        //open(STDOUT_FILENO,O_WRONLY);
        if(fout < 0){
          perror("Nothing opened");
          exit(-1);
        }
        //read(source, buf, sizeof(source))>(source)
        while((n = read(fin, buf, BLK))>0){//if not 0 error
          //if((write(fout,buf,n))!=n){
            if((write(STDOUT_FILENO,buf,n))!=n){
            perror("write error");
            exit(-1);
          }
        }
        exit(0);
      }
