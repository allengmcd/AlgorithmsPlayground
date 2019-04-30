#include <stdio.h>
#include <time.h>
#include <math.h>


#define TRUE 1
#define FALSE 0
#define bool int
#define status int
#define inQueue 0
#define inProcess 1
#define finished 2


struct queue {
    struct customer *nextCustomer;
    struct customer *currentCustomer;
}  *firstCustomer, *lastCustomer;

struct customer {
    int id;
    clock_t enterQueue;
    clock_t leaveQueue;
    clock_t enterProcessing;
    clock_t leaveProcessing;
    status customerStatus;
} *customers, *customerInProcessing;

int totalCustomers;
bool process;

clock_t processCustomer()
{
    struct customer *currCustomer = firstCustomer;
    firstCustomer = firstCustomer->nextCustomer;

    currCustomer->enterQueue = clock(); //Now
    currCustomer->customerStatus = inProcess;
    currCustomer->leaveQueue = currCustomer->enterQueue + 10.0f; //Done

    customerInProcessing = currCustomer;

    return currCustomer->leaveQueue;
}

void enterQueue()
{
    struct customer *newCustomer =  malloc(sizeof(struct queue));
    newCustomer->customerStatus = inQueue;
    lastCustomer->nextCustomer = newCustomer;
    lastCustomer = lastCustomer->nextCustomer;

    return;
}

void leaveQueue(struct customer *outCustomer)
{
    firstCustomer = firstCustomer->nextCustomer;
    free(outCustomer);

    return;
}


int main()
{
    clock_t endTime;
    clock_t currentTime = clock();
    process = FALSE;

    while(currentTime < endTime) 
    {
        int random;

        if(random > 10)
        {
            enterQueue();
        }
        
        if(process) 
        {
            processCustomer();
            process = TRUE;
        }

        if(customerInProcessing->leaveProcessing < currentTime)
        {
            process = FALSE;
        }
    }
}