#ifndef PRINTF_H
#define PRINTF_H

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* flags */
#define MINUS_F 1
#define PLUS_F 2
#define ZERO_F 4
#define HASH_F 8
#define SPACE_F 16

/* sizes */
#define SHORT_S 1
#define LONG_S 2

/**
 * struct fm - Struct op
 *
 * @fm: The format.
 * @fn: The function associated.
 */
struct fm
{
	char fm;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fm fm_t - Struct op
 *
 * @fm: The format.
 * @fm_t: The function associated.
 */
typedef struct fm fm_t;

int _printf(const char *format, ...);
int handle_print(const char *fm, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);

/* print functions */
int print_char(va_list list, char buffer[],
		int flags, int width, int precision, int size);
int print_str(va_list list, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list list, char buffer[],
		int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* functions for handling specifiers */
int get_size(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_width(const char *format, int *i, va_list list);
int get_flags(const char *format, int *i);

int write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_num1(int is_positive, int i, char buffer[],
		int flags, int width, int precision, int size);
int write_num2(int i, char buffer[], int flags, int width,
		int precision, int length, int pa, char extra_c);

/* extra functions */
int _isdigit(char);
int _is_printable(char);
long int convert_size_num(long int num, int size);

#endif /* PRINTF_H */
