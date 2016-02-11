/*
CSI-385-2 Assignment 1

Alexander Bean Apmann, Ethan Lamitie

Professor Hamed

Start Date: now

Due Date: later
*/


#include  <stdio.h>
#include  <sys/types.h>
#include  <sys/wait.h>
#include  <unistd.h>

#define processAmount 5

int childstuff1();

int imAglobal = 0;

int  main()
{
  pid_t  pid[processAmount];

  //fork child processes
  for(int i = 0; i < processAmount; i++)
  {

    if((pid[i] = fork()) < 0)//fork, if error return with error
    {
      perror("fork");
      return 1;
    }
    else if (pid[i] == 0)//if child do stuff and quit
    {
      childstuff1();

      return 0;
    }
  }

  int status;

  //wait for child processes
  for(int i = 0; i < processAmount; i++)
  {
    waitpid(-1,&status,0);
  }

  printf("everything is done!\n");

  return 0;
}

//child program for part 1
int childstuff1()
{
  pid_t mypid = getpid();


  for(int i = 0; i < 100; i++)//increment the global
  {
    imAglobal++;
    printf("My name is %d, I made the global %d\n", mypid, imAglobal);
  }


  return 0;
}
