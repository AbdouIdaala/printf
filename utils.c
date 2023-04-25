#include "main.h"

/**
 * _isdigit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * _is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int _is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * convert_size_num - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_num(long int num, int size)
{
	if (size == LONG_S)
		return (num);
	if (size == SHORT_S)
		return ((short)num);

	return ((int)num);
}
