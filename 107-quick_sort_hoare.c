#include "sort.h"

/**
 * swap - Swap two integers in an array.
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
 * hoare - Perform the Hoare partition scheme on an array.
 * @arr: Pointer to the integer array to be partitioned.
 * @low: The lower index of the partition.
 * @high: The upper index of the partition.
 * @size: Number of elements in the array.
 * Return: The index of the pivot element after partitioning.
 */
int hoare(int *arr, int low, int high, size_t size)
{
	int i;
	int j;
	int pivot;

	pivot = arr[high];
	i = low - 1;
	j = high + 1;
	while (i <= j)
	{
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);
		if (i < j)
		{
			swap(&arr[i], &arr[j]);
			print_array(arr, size);
		}
	}
	return (j);
}

/**
 * quick - Recursive function to perform quicksort.
 * @arr: Pointer to the integer array to be sorted.
 * @low: The lower index of the current partition.
 * @high: The upper index of the current partition.
 * @size: Number of elements in the array.
 *
 */
void quick(int *arr, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare(arr, low, high, size);
		quick(arr, low, pivot, size);
		quick(arr, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sort an integer array using the Hoare partition scheme.
 * @array: Pointer to the integer array to be sorted.
 * @size: Number of elements in the array.
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	quick(array, 0, size - 1, size);
}
