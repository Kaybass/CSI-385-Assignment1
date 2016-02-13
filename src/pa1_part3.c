// Currently the same thing as part1 lol

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define CHILDREN_COUNT 5

typedef struct process
{
    int pid;
    int turn;
} Process;

Process* forkSimulated(Process* parent);
void childFunction(Process* process);

int iGlobalVariable = 0;
int iPidCounter = 0;

// flag for a process to change when accessing the "shared memory"
int bMemFlag = 0;

int main()
{
    Process* children[CHILDREN_COUNT];

    // The parent process, won't do anything but fork
    Process* parent = (Process*)malloc(sizeof(Process));
    parent->pid = iPidCounter;

    for (int i = 0; i < CHILDREN_COUNT; i++)
    {
        iPidCounter++;
        children[i] = forkSimulated(parent);
    }

    while (iGlobalVariable < 100)
    {
        childFunction(children[0]);
        childFunction(children[1]);
        childFunction(children[2]);
        childFunction(children[3]);
        childFunction(children[4]);
    }

    for (int i = 0; i < CHILDREN_COUNT; i++)
    {
        if (children[i])
        {
            free(children[i]);
        }
    }

    return 0;
}

Process* forkSimulated(Process* parent)
{
    Process* child = (Process*)malloc(sizeof(Process));
    child->pid = parent->pid + iPidCounter;
    return child;
}

void childFunction(Process* process)
{
    // Is the shared memory being used by a different process?
    if (bMemFlag == 1)
    {
        // Do nothing (for now..?)
    }
    else
    {
        // The shared memory is open for use
        bMemFlag = 1;
        iGlobalVariable++;
        printf("Child with process ID: %d. Incremented Global to %d\n", process->pid, iGlobalVariable);
        // We're done with our once increment turn so we
        // turn the flag off
        bMemFlag = 0;
    }
}
