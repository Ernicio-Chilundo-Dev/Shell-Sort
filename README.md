# Shell Sort in C  

This project implements the **Shell Sort algorithm** in the C programming language. Shell Sort is an in-place comparison-based sorting algorithm and an optimized version of **Insertion Sort** that allows the exchange of far-apart elements to improve performance.  

## 📌 How the Algorithm Works  
- Start with a large gap between elements and reduce the gap after each pass.  
- Perform a gapped **insertion sort** for each gap size.  
- Repeat until the gap becomes **1**, at which point it behaves like a standard Insertion Sort.  

## ✅ Features  
- Simple and efficient sorting algorithm for medium-sized datasets.  
- Reduces the number of swaps compared to Insertion Sort.  
- Works in **O(n log² n)** time complexity in the average case.  

## 🛠️ Code Overview  
- **`shellSort()`**: Sorts the array using the Shell Sort algorithm.  
- **`main()`**: Demonstrates Shell Sort by sorting an example array and printing the results.  

### Example Code:
```c
#include <stdio.h>

void shellSort(int arr[], int n)
{
    // Start with a big gap, then reduced gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
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

▶️ How to Compile and Run

gcc shell_sort.c -o shell_sort
./shell_sort

🔍 Output Example

Original array: 20 33 1 4 23 43 2 0 
Sorted array: 0 1 2 4 20 23 33 43
