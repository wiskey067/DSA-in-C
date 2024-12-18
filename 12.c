#include <stdio.h>
#include <stdlib.h>

int isPrime(int n)
{
    int i;
    if(n==1)
    {
        return 0;
    }
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n,i,sum=0;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(isPrime(a[i]))
        {
            sum+=a[i];
        }
    }
    printf("The sum of all the prime elements of the array is: %d\n",sum);
    free(a);
    return 0;
}