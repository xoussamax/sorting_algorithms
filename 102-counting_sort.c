#include "sort.h"

/**
 * _max - Find the maximum value in an array of integers.
 *
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 *
 * Return: The maximum value found in the array.
 */
int _max(int *array, size_t size)
{
	size_t i;
	int  max;

	max = array[0];
	i = 1;
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

/**
 * counting_sort - Sorts an array of integers using
 * the Counting Sort algorithm.
 *
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 *
 */
void counting_sort(int *array, size_t size)
{
		int i;
		int *count_arr, *out_arr, max;

		if (!array || size < 2)
			return;
		max = _max(array, size);
		count_arr = (int *)malloc(sizeof(int) * (max + 1));
		if (!count_arr)
			return;
		out_arr = (int *)malloc(sizeof(int) * size);
		if (!out_arr)
		{
			free(count_arr);
			return;
		}
		for (i = 0; i <= max; i++)
			count_arr[i] = 0;
		for (i = 0; i < (int)size; i++)
			count_arr[array[i]]++;
		for (i = 1; (int)i <= max; i++)
			count_arr[i] += count_arr[i - 1];
		print_array(count_arr, max + 1);
		for (i = 0; i < (int)size; i++)
		{
			out_arr[count_arr[array[i]] - 1] = array[i];
			count_arr[array[i]]--;
		}
		for (i = 0; i < (int)size; i++)
			array[i] = out_arr[i];
		free(count_arr);
		free(out_arr);
}
