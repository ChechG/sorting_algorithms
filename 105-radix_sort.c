#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @size: size of array.
 */
void radix_sort(int *array, size_t size)
{
	int *temp;
	int i, k, l = 0, sorteado, div = 1, max_num, z;

	if (size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	max_num = max_int(array, (int)size);
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

/**
 * max_int - original a cambio
 * @array: array original.
 * @n: size of array.
 * Return: num of digits.
 */
int max_int(int *array, int n)
{
	int max = 0, max_num = 1, i;

	for (i = 0; i < n; i++)
		if (array[i] > max)
			max = array[i];
	while (max / 10 > 0)
	{
		max_num++;
		max = max / 10;
	}
	return (max_num);
}
