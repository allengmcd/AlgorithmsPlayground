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
    float enterQueue;
    float leaveQueue;
    float enterProcessing;
    float leaveProcessing;
    status customerStatus;
};

void processCustomer(struct customer *inCustomer)
{
    
}

void enterQueue(struct customer *inCustomer)
{
    struct queue *tempQueue = malloc(sizeof(struct queue));
    lastCustomer->nextCustomer = inCustomer;
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
    
}