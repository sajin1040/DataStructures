#include <stdio.h>
int binarySearch(int arr[], int size, int key) 
{
    int left = 0;
    int right = size - 1;

    while (left <= right) 
	{
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) 
		{
            return mid; 
        }

        if (arr[mid] < key) 
		{
            left = mid + 1;
        } 
		else 
		{
            right = mid - 1;
        }
    }

    return -1; 
}

int main() 
{
    int arr[] = {12, 21, 34, 45, 67, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the number to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, size, key);

    if (result != -1) 
	{
        printf("Number found at index %d.\n", result);
    } 
	else 
	{
        printf("Number not found in the array.\n");
    }

    return 0;
}

