#include "main.h"
#include <stdlib.h>

/**
 * format_specifier - Checks if there is a valid format specifier
 * @format: Possible format specifier
 * Return: Pointer to valid function or NULL
 */
static int (*format_specifier(const char *format))(va_list)
{
	unsigned int i;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"b", print_b},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"r", print_r},
		{"R", print_R},
		{"S", print_S},
		{"%", print_percent},
		{NULL, NULL}
	};
	for (i = 0; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
		{
			break;
		}
	}
	return (p[i].f);
}

/**
 * _printf - Prints anything
 * @format: List of argument types passed to the function
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list args;
	int (*f)(va_list);

	va_start(args, format);

	if (!format || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (format[i] == '%' && format[i + 1] == ' ' && !format[i + 2])
		return (-1);

	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		f = format_specifier(&format[i + 1]);
		if (f != NULL)
		{
			count += f(args);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(args);
	return (count);
}
