#include "sort.h"

/**
 * selection_sort - implementation of selection sort
 * @array: array to be sorted
 * @size: size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int smallest, index, tmp, flag = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		smallest = array[i];
		index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				index = j;
				flag = 1;
			}
		}
		if (flag)
		{
			tmp = array[i];
			array[i] = smallest;
			array[index] = tmp;
			print_array(array, size);
			flag = 0;
		}
	}
}
