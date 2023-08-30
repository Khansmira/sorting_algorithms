#include "sort.h"

void swp_ints(int *a, int *b);
int lomuto_part(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swp_ints - swap two ints in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swp_ints(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * lomuto_part - orders subset of an array of ints using
 * the lomuto partition scheme
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of the subset
 * @right: ending index of the subset
 *
 * Return: final partition index
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
	int *p, ab, bl;

	p = array + right;
	for (ab = bl = left; bl < right; bl++)
	{
		if (array[bl] < *p)
		{
			if (ab < bl)
			{
				swp_ints(array + bl, array + ab);
				print_array(array, size);
			}
			ab++;
		}
	}

	if (array[ab] > *p)
	{
		swp_ints(array + ab, p);
		print_array(array, size);
	}

	return (ab);
}

/**
 * lomuto_sort - implements the quicksort algorithm recursion style
 * @array: array of integers to sort
 * @size: size of the array
 * @left: starting index of the array partition
 * @right: ending index of the array partition
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_part(array, size, left, right);
		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);
	}
}

/**
 * quick_sort - sort an array of integers in s ascending order
 * using the quicksort algorithm.
 * @array: an array of integers.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
