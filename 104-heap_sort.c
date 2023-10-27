#include "sort.h"

/**
 * swap - Swaps two integers pointed to by a and b.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Heapifies a subtree in the array.
 * @arr: Pointer to the integer array.
 * @size: Size of the array.
 * @n: Index of the root of the subtree to be heapified.
 *
 */
void heapify(int *arr, int size, int n)
{
	int i;
	int max;

	i = size;
	while (i > 0)
	{
		if (i * 2 <= size)
		{
			max = i * 2 - 1;
			if ((i * 2) + 1 <= size)
			{
				if (arr[i * 2] > arr[max])
					max = i * 2;
			}
			if (arr[max] > arr[i - 1])
			{
				swap(&arr[i - 1], &arr[max]);
				print_array(arr, n);
				heapify(arr, size, n);
			}
		}
		i--;
	}
}

/**
 * sort - Sorts an array using the Heap Sort algorithm.
 * @arr: Pointer to the integer array.
 * @size: Size of the array.
 * @n: Size of the array (for printing purposes).
 *
 */
void sort(int *arr, int size, int n)
{
	if (size > 1)
	{
		swap(&arr[0], &arr[size - 1]);
		print_array(arr, n);
		heapify(arr, size - 1, n);
		sort(arr, size - 1, n);
	}
}

/**
 * heap_sort - Sorts an integer array using Heap Sort.
 * @array: Pointer to the integer array to be sorted.
 * @size: Size of the array.
 *
 */
void heap_sort(int *array, size_t size)
{
	heapify(array, size, size);
	sort(array, size, size);
}
