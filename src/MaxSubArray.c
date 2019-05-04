
#define INT_MAX 2147483647

struct FindMaxCrossingSubarrayReturn {
    int maxLeft;
    int maxRight;
    int sum;
};

int FindMaxCrossingSubarray(int *A, int low, int mid, int high)
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
    sum = 0;

    for(int j = mid+1; j < high; j++)
    {
        sum = sum + A[j];
        if(sum > rightSum)
        {
            rightSum = sum;
            maxLeft = j;
        }
    }

    return;
}

int FindMaxSubArray(int *inA, int low, int high)
{
    
}

int main()
{

    return 0;
}