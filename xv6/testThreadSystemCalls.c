#include "types.h"
#include "user.h"
#include "stat.h"
#include <stddef.h>

void printer(){
  printf(1,"NOW\n");
}

int main(void){
  // int b = 10;
  // int *a = &b;
  printf(1, "%d\n", getThreadID());
  exit();
}
