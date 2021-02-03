#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @size: size of array.
 */
void radix_sort(int *array, size_t size)
{
	int *temp = malloc(sizeof(int) * size);
	int i, k, l = 0, sorteado, div = 1, max = 0, max_num = 1, z = 0;

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	while (max / 10 > 0)
	{
		max_num++;
		max = max / 10;
	}
	while (l < max_num)
	{
		k = 0;
		z = 0;
		while (k < 10)
		{
			for (i = 0; i < (int)size; i++)
			{
				sorteado = array[i];
				sorteado = (sorteado / div) % 10;
				while (sorteado >= 0)
				{
					if (sorteado == k)
					{
						temp[z] = array[i];
						z++;
						break;
					}
					break;
				}
			}
			k++;
		}
		div *= 10;
		l++;
		print_array(temp, size);
		switch1(array, temp, (int)size);
	}
	free(temp);
}

/**
 * switch1 - original = cambio
 * @original: array original.
 * @cambio: valores para cambiar.
 * @size: size of array.
 */
void switch1(int *original, int *cambio, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		original[i] = cambio[i];
	}
}
