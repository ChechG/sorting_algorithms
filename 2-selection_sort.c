#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int lower = 0, temp = 0, first = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		first = array[i];
		lower = first;
		for (j = i; j < size; j++)
		{
			if (lower > array[j])
			{
				lower = array[j];
				temp = j;
			}
		}
		if (lower < first)
		{
			array[i] = lower;
			array[temp] = first;
			print_array(array, size);
		}
	}
}
