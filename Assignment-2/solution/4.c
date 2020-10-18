#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i <n ; ++i)
    scanf("%d", &arr[i]);
    
    int left = 0;
    int right = n-1;
    int mid = (right+left)/2;

    while(left<=right)
    {
        mid = (right+left)/2;
        if(arr[mid-1] < arr[mid]&& arr[mid+1] < arr[mid])
        break;
        else if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1])
        {
            right = mid-1;
        }
        else if(arr[mid] > arr[mid-1] &&arr[mid] < arr[mid+1])
        {
            left = mid+1;
        }
    }

    printf("%d\n",arr[mid]);

    return 0;
}