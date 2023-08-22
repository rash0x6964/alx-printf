#include "main.h"

/**
 * _putbinary - convert unsigned int to binary
 * @n: number
 * @len: length
 * Return: nothing
 */
void _putbinary(unsigned int n, int *len)
{
	if (n > 1)
		_putbinary(n / 2, len);
	*len += _putchar((n % 2) + '0');
}
