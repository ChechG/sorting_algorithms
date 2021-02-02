#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @size: size of array.
 */
void merge_sort(int *array, size_t size)
{
	int *barray = malloc(sizeof(int) * size);

	TopDownMergeSort(array, barray, (int)size);
}

/**
 * TopDownMergeSort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @barray: array to work on.
 * @n: size of array.
 */
void TopDownMergeSort(int *array, int *barray, int n)
{
	CopyArray(array, 0, n, barray);
	TopDownSplitMerge(barray, 0, n, array);
}

/**
 * TopDownSplitMerge - sorts an array of integers in ascending order
 * @barray: array to sort.
 * @ini: first index.
 * @end: last index.
 * @array: array to work on.
 */
void TopDownSplitMerge(int *barray, int ini, int end, int *array)
{
	int mid, i;

	if (end - ini <= 1)
		return;
	mid = (end + ini) / 2;
	TopDownSplitMerge(array, ini, mid, barray);
	TopDownSplitMerge(array, mid, end, barray);
	printf("Merging...\n");
	TopDownMerge(barray, ini, mid, end, array);
	printf("[Done]: ");
	for (i = ini; i < end; i++)
	{
		printf("%d", array[i]);
		if (i < end - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * TopDownMerge - sorts an array of integers in ascending order
 * @array: array to sort.
 * @ini: first index.
 * @mid: middle index.
 * @end: last index.
 * @barray: array to work on.
 */
void TopDownMerge(int *array, int ini, int mid, int end, int *barray)
{
	int i = ini, j = mid, k;

	for (k = ini; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			barray[k] = array[i];
			i = i + 1;
		}
		else
		{
			barray[k] = array[j];
			j = j + 1;
		}
	}
	printf("[left]: ");
	for (i = ini; i < mid; i++)
	{
		printf("%d", array[i]);
		if (i < mid - 1)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (i = mid; i < end; i++)
	{
		printf("%d", array[i]);
		if (i < end - 1)
			printf(", ");
	}
	printf("\n");
}
/**
 * CopyArray - sorts an array of integers in ascending order
 * @array: array to sort.
 * @ini: first index.
 * @mid: middle index.
 * @end: last index.
 * @barray: array to work on.
 */
void CopyArray(int *array, int ini, int end, int *barray)
{
	int k;

	for (k = ini; k < end; k++)
		barray[k] = array[k];
}