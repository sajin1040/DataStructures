#include <stdio.h>


int main() 
{
    int num, i;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &num);

    int arr[num];
    printf("Enter the elements of the set: ");
    for (i = 0; i < num; i++) 
	{
        scanf("%d", &arr[i]);
    }

    int odd_count = 0, even_count = 0;
    for (i = 0; i < num; i++) 
	{
        if (arr[i] % 2 == 0) 
		{
            even_count++;
        } else {
            odd_count++;
        }
    }

    printf("Number of even numbers in the set: %d\n", even_count);
    printf("Number of odd numbers in the set: %d\n", odd_count);

    return 0;

}
