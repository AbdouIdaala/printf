#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 *
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int j, k, flags = 0;
	const char c_flags[] = {'-', '+', '#', ' ', '0', '\0'};
	const int arr_flags[] = {
		MINUS_F, PLUS_F, ZERO_F, HASH_F, SPACE_F, 0
	};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (j = 0; c_flags[j] != '\0'; j++)
			if (format[k] == c_flags[j])
			{
				flags |= arr_flags[j];
				break;
			}
		if (c_flags[j] == 0)
			break;
	}
	*i = k - 1;

	return (flags);
}
