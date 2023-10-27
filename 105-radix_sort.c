#include "sort.h"

/**
 * _max - Find the maximum element in an array of integers.
 * @arr: Pointer to the integer array.
 * @size: Number of elements in the array.
 *
 * Return: The maximum element in the array.
 */
int _max(int *arr, size_t size)
{
	int max;
	size_t i;

	max = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

/**
 * count_sort - Perform counting sort on an array of
 * integers based on digit position.
 * @arr: Pointer to the integer array to be sorted.
 * @size: Number of elements in the array.
 * @n: The current digit position for sorting.
 * @sorted: Pointer to the output array where
 * the sorted elements will be stored.
 *
 */
void count_sort(int *arr, size_t size, int n, int *sorted)
{
	int count[10] = {0};
	int i;

	i = 0;
	while (i < (int)size)
	{
		count[(arr[i] / n) % 10]++;
		i++;
	}
	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}
	i = size - 1;
	while (i >= 0)
	{
		sorted[count[(arr[i] / n) % 10]-- - 1] = arr[i];
		i--;
	}
	i = 0;
	while (i < (int)size)
	{
		arr[i] = sorted[i];
		i++;
	}
}

/**
 * radix_sort - Sort an array of integers using radix sort.
 * @array: Pointer to the integer array to be sorted.
 * @size: Number of elements in the array.
 *
 */
void radix_sort(int *array, size_t size)
{
	int *sorted;
	size_t i;
	int max;

	if (!array || size < 2)
		return;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	max = _max(array, size);
	i = 1;
	while (max / i > 0)
	{
		count_sort(array, size, i, sorted);
		i *= 10;
		print_array(array, size);
	}
	free(sorted);
}
