#include <stdio.h>
int linearSearch(int arr[], int size, int key) 
{
    for (int i = 0; i < size; i++) 
	{
        if (arr[i] == key)
		{
            return i; 
        }
    }
    return -1;
}

int main() 
{
    int arr[] = {12, 45, 67, 89, 34, 21};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the number to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, size, key);

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

