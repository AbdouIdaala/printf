#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fm: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @i: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: 1 or 2;
 */
int handle_print(const char *fm, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int j, count_len = 0, printed_chars = -1;

	fm_t fm_specifiers[] = {
		{'s', print_str},
		{'c', print_char},
		{'i', print_int},
		{'d', print_int},
		{'%', print_percent},
		{'\0', NULL},
	};
	for (j = 0; fm_specifiers[j].fm != '\0'; j++)
		if (fm[*i] == fm_specifiers[j].fm)
			return (fm_specifiers[j].fn(list, buffer, flags, width, precision, size));
	if (fm_specifiers[j].fm == '\0')
	{
		if (fm[*i] == '\0')
			return (-1);
		count_len += write(1, "%%", 1);
		if (fm[*i - 1] == ' ')
			count_len += write(1, " ", 1);
		else if (width)
		{
			--*i;
			while (fm[*i] != ' ' && fm[*i] != '%')
				--*i;
			if (fm[*i] == ' ')
				--*i;
			return (1);
		}
		count_len += write(1, &fm[*i], 1);
		return (count_len);
	}
	return (printed_chars);
}
