#include "types.h"
#include "user.h"
#include "stat.h"

#define NCHILD 10
int main(void){
  int pid;
  ticketLockInit();

  pid = fork();
  for(int i = 0; i < NCHILD; i++)
    if (pid < 0){
      printf(1, "fork failed\n");
      exit();
    } else if(pid > 0)
      pid = fork();
  if(pid < 0) {
    printf(1, "fork failed\n");
    exit();
  } else if(pid == 0){
    printf(1, "Child adding to shared counter\n");
    ticketLockTest();
  } else{
    for(int i = 0; i < NCHILD * NCHILD; i++)
      wait();
    printf(1, "User program finished\n");
    printf(2, "Ticket lock value: %d\n", ticketLockTest() - 1);
  }
  exit();
}
