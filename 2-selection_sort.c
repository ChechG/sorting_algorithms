#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int aux = 0, temp = 0;

	for (i = 0; i < size; i++)
	{
		first = array[i]
		for (j = i; j < size; j++)
		{
			temp = array[i];
			if (temp > array[j])
			{
				aux = array[j];
				array[j] = temp;
				temp = aux;
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
