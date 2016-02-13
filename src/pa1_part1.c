#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define CHILDREN_COUNT 5

typedef struct process
{
    int pid;
    int globalCopy;
} Process;

Process* forkSimulated(Process* parent);
void childFunction(Process* process);

int iGlobalVariable = 0;
int iPidCounter = 0;

int main()
{
    Process* children[CHILDREN_COUNT];

    // The parent process, won't do anything but fork
    Process* parent = (Process*)malloc(sizeof(Process));
    parent->pid = iPidCounter;
    parent->globalCopy = iGlobalVariable;

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

    return 0;
}

Process* forkSimulated(Process* parent)
{
    Process* child = (Process*)malloc(sizeof(Process));
    child->pid = parent->pid + iPidCounter;
    child->globalCopy = parent->globalCopy;
    return child;
}

void childFunction(Process* process)
{
    process->globalCopy++;
    printf("Child with process ID: %d. Incremented Global to %d\n", process->pid, process->globalCopy);
}
