#include "sort.h"

/**
 * swp_ints - Swap two ints in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swp_ints(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * with the selection sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *c;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		c = array + a;
		for (b = a + 1; b < size; b++)
			c = (array[b] < *c) ? (array + b) : c;

		if ((array + a) != c)
		{
			swp_ints(array + a, c);
			print_array(array, size);
		}
	}
}
