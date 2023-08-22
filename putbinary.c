#include "main.h"

/**
 * putbinary - convert unsigned int to binary
 * @n: number
 * Return: length
 */
void _putbinary(unsigned int n, int *len)
{
	if (n > 1)
	    _putbinary(n / 2, len);
	*len += _putchar((n % 2) + '0');
}
