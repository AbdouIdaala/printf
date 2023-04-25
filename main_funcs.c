#include "main.h"

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int percision, int size)
{
	char c = va_arg(types, int);

	return (write_char(c, buffer, flags, width, percision, size));
}

/**
 * print_str - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_str(va_list types, char buffer[],
		int flags, int width, int percision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(percision);
	UNUSED(buffer);

	if(str == NULL)
	{
		str = "(nil)";
		if (percision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (percision >= 0 && percision < length)
		length = percision;
	if (width > length)
	{
		if (flags & MINUS_F)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ",1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
		int flags, int width, int percision, int size)
{
	UNUSED(flags);
	UNUSED(width);
	UNUSED(percision);
	UNUSED(types);
	UNUSED(size);
	UNUSED(buffer);

	return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int percision, int size)
{
	int i = BUFF_SIZE - 2, is_negative = 0;
	long int ln = va_arg(types, long int);
	unsigned long int uln;

	ln = convert_size_num(ln, size);
	if (ln == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	uln = (unsigned long int)ln;

	if (ln < 0)
	{
		uln = (unsigned long int)((-1) * ln);
		is_negative = 1;
	}

	while (uln > 0)
	{
		buffer[i--] = (uln % 10) + '0';
		uln = uln / 10;
	}
	i++;

	return (write_num1(is_negative, i, buffer, flags, width, percision, size));
}
