#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int j, d = 0;

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		if (_isdigit(format[j]))
		{
			d *= 10;
			d += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			d = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = j - 1;

	return (d);
}
