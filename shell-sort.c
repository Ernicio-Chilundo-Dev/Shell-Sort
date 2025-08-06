#include <stdio.h>

void shellSort(int arr[], int n)
{
    // Start with a big gap, then redeced gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        //Do a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            for (j = i; j>= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }

    }
}

int main(void)
{
    int arr[] = {20, 33, 1, 4, 23, 43, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    shellSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}