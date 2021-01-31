#include "sort.h"
/**
 * bubble_sort -  sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int temp;

	n = size - 1;
	for (; n > 0; n = n - 1)
	{
		for (i = 0; i < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
}
