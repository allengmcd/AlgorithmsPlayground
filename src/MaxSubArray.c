#include <time.h>
#include <stdlib.h>
#include <stdio.h>


#define INT_MAX 214748
#define SIZE 20

struct FindMaxCrossingSubarrayReturn {
    int maxLeft;
    int maxRight;
    int sum;
};

struct FindMaxCrossingSubarrayReturn FindMaxCrossingSubarray(int *A, int low, int mid, int high)
{
    int maxLeft = 0;
    int leftSum = INT_MAX * -1;
    int sum = 0;

    for(int i = mid; i > low - 1; i--)
    {
        sum = sum + A[i];
        if(sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = INT_MAX * -1;
    int maxRight = 0;
    sum = 0;

    for(int j = mid+1; j < high+1; j++)
    {
        sum = sum + A[j];
        if(sum > rightSum)
        {
            rightSum = sum;
            maxRight = j;
        }
    }

    struct FindMaxCrossingSubarrayReturn returnValue = {maxLeft, maxRight, leftSum+rightSum};
    return returnValue;
}

struct FindMaxCrossingSubarrayReturn FindMaxSubArray(int *A, int low, int high)
{
    struct FindMaxCrossingSubarrayReturn right, left, cross;    

    if(high == low)
    {
        struct FindMaxCrossingSubarrayReturn returnValue = { low, high, A[low] };
        return returnValue;
    }
    else
    {
        int mid = (high + low) / 2;
        right = FindMaxSubArray(A, low, mid);
        left = FindMaxSubArray(A, mid + 1, high);
        cross = FindMaxCrossingSubarray(A, low, mid, high);

        if(left.sum >= right.sum && left.sum >= cross.sum)
        {
            return left;
        }
        else if(right.sum >= left.sum && right.sum >= cross.sum)
        {
            return right;
        }
        else
        {
            return cross;
        }
        
    }
}

void DisplayArray(int *array, int start, int finish)
{
    for(int i = start; i < finish+1; i++)
    {
        printf("%d: %d \n", i, array[i]);
    }
}

int main()
{
    int Array[SIZE] = { 1 };

    srand(time(NULL));   // Initialization, should only be called once.

    for(int i = 0; i < SIZE; i++)
    {
        int r = rand() % 100 - 50; 
        Array[i] = r;
    }

    DisplayArray(Array, 0, SIZE-1);
    printf("\n");


    struct FindMaxCrossingSubarrayReturn test = FindMaxSubArray(Array, 0, SIZE-1);

    DisplayArray(Array, test.maxLeft, test.maxRight);

    return 0;
}