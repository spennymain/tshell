#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_system.h"

char* read_line(void);

int main(void) {  
          
  char* line;

  while (1) {
    printf(">");
    line=read_line();
    if (strlen(line)>1){
    my_system(line); //to become my_system();
    }
    else{
      exit(0);     
  
    }
}
}
char* read_line(void)
{
  char *buffer=NULL;
  size_t  n = 0;      
  getline(&buffer, &n, stdin);
  return buffer;
}
