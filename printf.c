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

	if (str[loc->i] == 'c')
		len = _putchar(va_arg(argp, int));
	else if (str[loc->i] == 's')
		len = _putstr(va_arg(argp, char *));
	else if (str[loc->i] == '%')
		len = _putchar('%');
	else if (str[loc->i] == 'd' || str[loc->i] == 'i')
		len = _putnbr(va_arg(argp, int));
	else if (str[loc->i] == 'b')
		_putbinary(va_arg(argp, unsigned int), &len);
	else if (str[loc->i] == 'o')
		len = _putNbBase(va_arg(argp, unsigned int), 8, "01234567");
	else if (str[loc->i] == 'u')
		len = _putNbBase(va_arg(argp, unsigned int), 10, "0123456789");
	else if (str[loc->i] == 'x')
		len = _putNbBase(va_arg(argp, unsigned int), 16, "0123456789abcdef");
	else if (str[loc->i] == 'X')
		len = _putNbBase(va_arg(argp, unsigned int), 16, "0123456789ABCDEF");
	else if (str[loc->i] == 'p')
	{
		len = _putstr("0x");
		len += _putNbBase(va_arg(argp, unsigned long), 16, "0123456789abcdef");
	}
	else
	{
		len = _putchar('%');
		len += _putchar(str[loc->i]);
	}
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
			if (!format[loc.i])
			{
				va_end(argp);
				return (-1);
			}
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

