#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @size: size of array.
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, i = 0, x, k = 0;
	int m, actual = 0, y = 0, posicion;
	int *array_0, *array_1;

	if (size < 2)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	array_0 = malloc(sizeof(int) * max + 1);
	array_1 = malloc(sizeof(int) * size);
	for (k = 0; k < (int)size; k++)
	{
		x = array[k];
		array_0[x] += 1;
	}
	for (m = 1; m <= max + 1; m++)
	{
		actual = array_0[m];
		array_0[m] = actual + array_0[m - 1];
	}
	print_array(array_0, max + 1);
	for (y = 0; y < (int)size; y++)
	{
		posicion = array[y];
		for (x = 0; x <= max; x++)
		{
			if (posicion == x)
			{
				array_1[array_0[posicion]] = posicion;
				array_0[posicion] -= 1;
			}
		}
	}
	for (i = 1; i <= (int)size; i++)
		array[i - 1] = array_1[i];
	free(array_0);
	free(array_1);
}
