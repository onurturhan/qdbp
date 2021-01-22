#include <stdio.h>
#include <stdlib.h>
#include "qdbp.h"

void callback(void *arg) {
  char *ptr = arg;
  if (ptr[123] == 'e') {
    printf("Error: ptr[123] has an invalid value!\n");
    // Check stack backtrace to see who is to blame.
  }
}

void __attribute__ ((constructor)) init(){
    printf("init()\n");
}

int main(int argc, char *argv[]){
  char *ptr = malloc(256);
  qdbp_trap(ptr[123], callback, ptr);
  ptr[123] = 'e';
  // As if "callback(ptr);" was here.
  return(0);
}
