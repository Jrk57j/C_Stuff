#include <stdio.h>

int main(){
  //long nc;
  //nc = 0;
  //printf("Enter stuff\n");
  // while(getchar() != EOF){
  //   ++nc;
  //   printf("%ld\n",nc);
  // }
  // printf("Enter stuff\n");
  // for(nc = 0; getchar() != EOF; nc++){
  //   printf("%ld\n",nc);
  // }

  //line counting
  // long lc;
  // printf("This counts lines\n");
  // int c;
  // while((c = getchar())!= EOF){
  //   if(c == '\n'){
  //     ++lc;
  //   }
  //   printf("%ld\n",lc);
  // }
  // execrise 1.8
  // int c;
  // long bl= 0,tb = 0,nl = 0;
  // while((c = getchar())!=EOF){
  //   if(c == ' '){
  //     ++bl;
  //     printf("blank line count %ld\n",bl);
  //   }
  //   if(c == '\t'){
  //     ++tb;
  //     printf("Tabbed count %ld\n",tb);
  //   }
  //   if(c == '\n'){
  //     ++nl;
  //     printf("New line count %ld\n",nl);
  //   }
  // }

  //exercise 1.9
  // int c;
  // while((c = getchar())!= EOF){
  //   if(c == ' '){//first blank
  //     while((c = getchar()) == ' '){//next blank
  //       ;
  //     }
  //     putchar(' ');
  //     putchar(c);
  //   }
  //   else{
  //     putchar(c);
  //   }
  // }
 //exercise 1.10

  // int c;
  // while((c = getchar())!= EOF){
  //   if(c == '\t'){
  //       printf("\\t");
  //   }
  //   if(c == '\b'){
  //     putchar('\\');
  //     putchar('b');
  //   }
  //   if(c == '\\'){
  //     printf("\\");
  //   }
  //   if(c != EOF){
  //     putchar(c);
  //   }
  // }
  //exercise 1.11
  int c;
  while((c = getchar())!= EOF){
    if(c == '\n' || c == '\t' || c == ' '){
      putchar('\n');
    }putchar(c);
  }
}
