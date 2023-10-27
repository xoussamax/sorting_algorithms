#include "sort.h"

/**
 * swap - Swaps two integer values.
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
 * bitonic_merge - Merges two halves of an array in bitonic order.
 * @arr: Pointer to the integer array to be merged.
 * @low_idx: The index of the lower bound of the current range.
 * @size: Number of elements in the current range.
 * @direction: Sorting direction (1 for ascending, 0 for descending).
 *
 */
void bitonic_merge(int *arr, int low_idx, size_t size, int direction)
{
	int i;
	int j;

	if (size <= 1)
		return;
	i = low_idx;
	j = size / 2;
	while (i < low_idx + j)
	{
		if (direction == (arr[i] > arr[i + j]))
			swap(&arr[i], &arr[i + j]);
		i++;
	}
	bitonic_merge(arr, low_idx, j, direction);
	bitonic_merge(arr, low_idx + j, j, direction);

}

/**
 * show_process - Display the process or result of merging during Bitonic Sort.
 * @arr: Pointer to the integer array being processed.
 * @low_idx: The index of the lower bound of the current range.
 * @size: Number of elements in the current range.
 * @direction: Sorting direction (1 for ascending, 0 for descending).
 * @n: The size of the main integer array to be sorted.
 * @msg: Flag to determine whether to display
 * a process or result message (1 for process, 0 for result).
 *
 */
void show_process(int *arr, int low_idx, size_t size,
		int direction, int n, int msg)
{
	if (msg)
		printf("Merging [%ld/%d] ", size, n);
	else
		printf("Result [%ld/%d] ", size, n);
	if (direction)
		printf("(UP):\n");
	else
		printf("(DOWN):\n");
	print_array(arr + low_idx, size);
}

/**
 * bitonic - Sorts an array using the bitonic sorting algorithm.
 * @arr: Pointer to the integer array to be sorted.
 * @low_idx: The index of the lower bound of the current range.
 * @size: Number of elements in the current range.
 * @n: The size of the main integer array to be sorted.
 * @direction: Sorting direction (1 for ascending, 0 for descending).
 *
 */
void bitonic(int *arr, int low_idx, size_t size, int direction, int n)
{
	int k;

	if (size <= 1)
		return;
	k = size / 2;
	show_process(arr, low_idx, size, direction, n, 1);
	bitonic(arr, low_idx, k, 1, n);
	bitonic(arr, low_idx + k, k, 0, n);
	bitonic_merge(arr, low_idx, size, direction);
	show_process(arr, low_idx, size, direction, n, 0);
}

/**
 * bitonic_sort - Sorts an integer array using the Bitonic Sort algorithm.
 * @array: Pointer to the integer array to be sorted.
 * @size: Number of elements in the array.
 *
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic(array, 0, size, 1, size);
}
