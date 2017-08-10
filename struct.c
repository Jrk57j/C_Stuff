#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct words{
  int i;
  char a[64];
};

int main(void){
  struct words a;
  struct words *b;
  a.i = 30;
  printf("a.i: %d\n",a.i);
  strcpy(a.a,"these be words");
  printf("%s\n", a.a);

    b = (struct words*)malloc(sizeof(struct words)+1);
    b->i=20;
    strcpy(b->a,"foood\n");
    printf("b.i: %d\nb.c: %s",b->i,b->a);
    return 0;

}
