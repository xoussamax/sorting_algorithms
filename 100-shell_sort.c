#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *               using the Shell Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t i;
	size_t j;
	int temp;

	if (!array || size < 2)
		return;
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
			i++;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
