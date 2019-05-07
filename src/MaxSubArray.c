#include <time.h>
#include <stdlib.h>


#define INT_MAX 2147483647

struct FindMaxCrossingSubarrayReturn {
    int maxLeft;
    int maxRight;
    int sum;
};

struct FindMaxCrossingSubarrayReturn FindMaxCrossingSubarray(int *A, int low, int mid, int high)
{
    int maxLeft;
    int leftSum = INT_MAX;
    int sum = 0;

    for(int i = mid; i > low; i--)
    {
        sum = sum + A[i];
        if(sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = INT_MAX * -1;
    int maxRight;
    sum = 0;

    for(int j = mid+1; j < high; j++)
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

void DisplayArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        //printf("%d: %d\n", i, array[i]);
    }
}

int main()
{
    int SIZE = 100;
    int Array[100] = { 1 };

    srand(time(NULL));   // Initialization, should only be called once.

    for(int i = 0; i < 100; i++)
    {
        int r = rand() % 100 - 100; 
        Array[i] = r;
    }

    DisplayArray(Array, 100);
    FindMaxSubArray(Array, 0, 99);
    DisplayArray(Array, 100);

    return 0;
}