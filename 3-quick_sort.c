#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps the values of two integers.
 *
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
 * partition - Partitions an array for the Quicksort algorithm.
 *
 * @arr: Pointer to the array to be partitioned.
 * @l: The low index of the partition.
 * @h: The high index of the partition.
 * @size: Size of the array.
 * Return: The index of the pivot element in the partitioned array.
 */
int partition(int *arr, int l, int h, size_t size)
{
	int pivot;
	int i;
	int j;

	pivot = arr[h];
	i = l - 1;
	j = l;
	while (j < h)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i < j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
		j++;
	}
	if (arr[i + 1] > arr[h])
	{
		swap(&arr[i + 1], &arr[h]);
		print_array(arr, size);
	}
	return (i + 1);
}

/**
 * quick_rec - Recursively sorts an array using the Quicksort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @low: The low index of the current partition.
 * @high: The high index of the current partition.
 * @size: Size of the array.
 *
 */
void quick_rec(int *array, int low, int high, int size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_rec(array, low, pivot - 1, size);
		quick_rec(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array using the Quicksort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 */
void quick_sort(int *array, size_t size)
{
	quick_rec(array, 0, size - 1, size);
}
