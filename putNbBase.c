#include "main.h"

/**
 * _putNbBase - convert number to any base u want
 * @nb: the number in base 10
 * @base: the base u want to convert to
 * @array: your base as array
 * Return: length of number
 */
int _putNbBase(unsigned long nb, unsigned long base, char *array)
{
	int l;

	l = 0;
	if (nb > base - 1)
	{
		l = _putNbBase(nb / base, base, array);
		_putNbBase(nb % base, base, array);
	}
	else
		_putchar(array[nb]);
	return (l + 1);
}

