#include "sort.h"

/**
 * counting_sort - implementation of counting sort
 * @array: array to be sorted
 * @size: size of array
 *
 */
void counting_sort(int *array, size_t size)
{
	int largest = 0;
	int *counting = NULL, *output = NULL;
	size_t i, counting_size;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
	}
	counting_size = largest + 1;
	counting = malloc(sizeof(*counting) * counting_size);
	if (counting == NULL)
		return;
	for (i = 0; i < counting_size; i++)
		counting[i] = 0;
	for (i = 0; i < size; i++)
		counting[array[i]] += 1;
	for (i = 0; i < counting_size; i++)
	{
		if (i == 0)
			continue;
		counting[i] += counting[i - 1];
	}
	print_array(counting, counting_size);
	output = malloc(sizeof(*output) * size);
	for (i = 0; i < size; i++)
		output[--counting[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(counting);
	free(output);
}
