#include "main.h"

/**
 * checks - check for the exact specifier
 * @argp: the va_list
 * @str: the string format
 * @loc: the struct of vars
 * Return: length
 */
static int	checks(va_list	argp, const char *str, t_locals *loc)
{
	int	len;

	len = 0;
	if (!str[loc->i])
		return (-1);
	if (str[loc->i] == 'c')
		len = _putchar(va_arg(argp, int));
	else if (str[loc->i] == 's')
		len = _putstr(va_arg(argp, char *));
	else
		len = _putchar(str[loc->i]);
	loc->i++;
	return (len);
}

/**
 * _printf - produces out_put according to a format.
 * @format: character string
 * Return: length of the out_put
 */
int _printf(const char *format, ...)
{
	va_list		argp;
	t_locals	loc;

	va_start(argp, format);

	loc.i = 0;
	loc.glen = 0;
	if (!format)
		return (-1);

	while (format[loc.i])
	{
		if (format[loc.i] == '%')
		{
			loc.i++;
			loc.glen += checks(argp, format, &loc);
		}
		else
		{
			write(1, &format[loc.i], 1);
			loc.i++;
			loc.glen++;
		}
	}
	va_end(argp);
	return (loc.glen);
}

