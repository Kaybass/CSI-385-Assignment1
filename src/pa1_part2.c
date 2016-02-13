// Currently the same thing as part1 lol

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define CHILDREN_COUNT 5
#define INIT_VALUE 0

typedef struct pipe
{
    int value;
} Pipe;

typedef struct process
{
    int pid;
    Pipe* pPipe;
} Process;


Process* forkSimulated(Process* parent);
void     childFunction(Process* process);
int      myRead(Pipe * thePipe);
void     myWrite(int value, Pipe * thePipe);

int iPidCounter = 0;
int main()
{


    Process* children[CHILDREN_COUNT];

    Pipe * thePipe = (Pipe*)malloc(sizeof(pipe));

    // The parent process, won't do anything but fork
    Process* parent = (Process*)malloc(sizeof(Process));
    parent->pid = iPidCounter;
    parent->pPipe = thePipe;

    for (int i = 0; i < CHILDREN_COUNT; i++)
    {
        iPidCounter++;
        children[i] = forkSimulated(parent);
    }

    for (int i = 0; i < CHILDREN_COUNT; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            childFunction(children[i]);
        }
    }

    for (int i = 0; i < CHILDREN_COUNT; i++)
    {
        if (children[i])
        {
            free(children[i]);
        }
    }

    free(thePipe);

    return 0;
}

Process* forkSimulated(Process* parent)
{
    Process* child = (Process*)malloc(sizeof(Process));
    child->pid = parent->pid + iPidCounter;
    child->pPipe = parent->pPipe;
    return child;
}

void childFunction(Process* process)
{
    int i;
    i = myRead(process->pPipe);

    i++;

    

    myWrite(i, process->pPipe);
}

int myRead(Pipe * thePipe)
{
    return thePipe->value;
}

void myWrite(int value, Pipe * thePipe)
{
    thePipe->value = value;
}
