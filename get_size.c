#include "main.h"

/**
 * get_size -Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int j = *i + 1, size = 0;

	if (format[j] == 'l')
		size = LONG_S;
	if (format[j] == 'h')
		size = SHORT_S;

	if (size == 0)
		*i = j - 1;
	else
		*i = j;

	return (size);
}
