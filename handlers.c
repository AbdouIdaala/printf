#include "main.h"

/**
 * write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char pa = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & ZERO_F)
		pa = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE] = pa;

		if (flags & MINUS_F)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_num1 - Prints a string
 * @is_negative: List of arguments
 * @i: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_num1(int is_negative, int i, char buffer[],
		int flags, int width, int percision, int size)
{
	int length = BUFF_SIZE - i - 1;
	char pa = ' ', extra_c = 0;

	UNUSED(size);

	if ((flags & ZERO_F) && !(flags & MINUS_F))
		pa = '0';
	if (is_negative)
		extra_c = '-';
	if (flags & PLUS_F)
		extra_c = '+';
	if (flags & SPACE_F)
		extra_c = ' ';

	return (write_num2(i, buffer, flags, width, percision,
				length, pa, extra_c));
}

/**
 * write_num2 - Write a number using a bufffer
 * @i: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @precision: Precision specifier
 * @length: Number length
 * @pa: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num2(int i, char buffer[], int flags, int width,
		int percision, int length, int pa, char extra_c)
{
	int j, pa_start = 1;

	if (percision == 0 && i == BUFF_SIZE - 2)
	{
		if (buffer[i] == '0' && width == 0)
			return (0);
		if (buffer[i] == '0')
			buffer[i] = pa = ' ';
	}
	if (percision > 0 && percision < length)
		pa = ' ';
	while (percision > length)
		buffer[--i] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (j = 1; j < (width - length) + 1; j++)
			buffer[j] = pa;
		buffer[j] = '\0';
		if (flags & MINUS_F && pa == ' ')
		{
			if (extra_c)
				buffer[--i] = extra_c;
			return (write(1, &buffer[i], length) +
					write(1, &buffer[1], i - 1));
		}
		else if (!(flags & MINUS_F))
		{
			if (pa == ' ')
			{
				if (extra_c)
					buffer[--i] = extra_c;
				return (write(1, &buffer[1], i - 1) +
						write(1, &buffer[i], length));
			}
			else if (pa == '0')
			{
				if (extra_c)
					buffer[--pa_start] = extra_c;
				return (write(1, &buffer[pa_start], i - pa_start) +
						write(1, &buffer[i], length - (1 - pa_start)));
			}
		}
	}
	if (extra_c)
		buffer[--i] = extra_c;
	return (write(1, &buffer[i], length));
}
