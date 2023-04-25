#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int j = *i + 1;
	int perc = -1;

	if (format[j] != '.')
		return (perc);

	perc = 0;
	for (j += 1; format[j] != '\0'; j++)
	{
		if (_isdigit(format[j]))
		{
			perc *= 10;
			perc += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			perc = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = j - 1;

	return (perc);
}
