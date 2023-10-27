#include "sort.h"

/**
 * show_msg - Display messages for the merging process.
 *
 * @arr:   The original array being merged.
 * @l:     The left index of the current merge.
 * @m:     The middle index of the current merge.
 * @r:     The right index of the current merge.
 * @sorted: The auxiliary sorted array used in merging.
 */

void show_msg(int *arr, int l, int m, int r, int *sorted)
{
	int i;
	int j;

	i = l;
	j = m + 1;
	printf("Merging...\n");
	printf("[left]: %d", arr[i++]);
	while (i <= m)
		printf(", %d", arr[i++]);
	printf("\n[right]: %d", arr[j++]);
	while (j <= r)
		printf(", %d", arr[j++]);
	printf("\n[Done]: %d", sorted[l++]);
	while (l <= r)
		printf(", %d", sorted[l++]);
	printf("\n");
}

/**
 * merge - Merge two subarrays into a single sorted array.
 *
 * @arr:    The original array to be merged.
 * @l:      The left index of the current merge.
 * @m:      The middle index of the current merge.
 * @r:      The right index of the current merge.
 * @sorted: The auxiliary sorted array used in merging.
 */
void merge(int *arr, int l, int m, int r, int *sorted)
{
	int i;
	int j;
	int k;

	i = l;
	j = m + 1;
	k = l;
	while (i <= m && j <= r)
	{
		if (arr[i] < arr[j])
			sorted[k++]  = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	while (i <= m)
		sorted[k++] = arr[i++];
	while (j <= r)
		sorted[k++] = arr[j++];
	show_msg(arr, l, m, r, sorted);
	while (l <= r)
	{
		arr[l] = sorted[l];
		l++;
	}
}

/**
 * merge_split - Recursive function to split and merge the array.
 *
 * @arr:    The original array to be sorted.
 * @l:      The left index of the current split.
 * @r:      The right index of the current split.
 * @sorted: The auxiliary sorted array used in merging.
 */
void merge_split(int *arr, int l, int r, int *sorted)
{
	int m;

	if (l < r)
	{
		m = l + (r - l + 1) / 2;
		merge_split(arr, l, m - 1, sorted);
		merge_split(arr, m, r, sorted);
		merge(arr, l, m - 1, r, sorted);
	}
}

/**
 * merge_sort - Sort an array using the merge sort algorithm.
 *
 * @array: The array to be sorted.
 * @size:  The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *sorted;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	merge_split(array, 0, size - 1, sorted);
	free(sorted);
}
