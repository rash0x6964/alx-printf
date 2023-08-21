#include "main.h"

/**
 * _putnbr - print number
 * @nb: the number u wanna print
 * Return: length of number
 */
int	_putnbr(int nb)
{
	long	nb1;
	int			l;

	nb1 = (long)nb;
	l = 0;
	if (nb1 < 0)
	{
		l = _putchar('-');
		nb1 *= -1;
	}
	if (nb1 > 9)
	{
		l += _putnbr(nb1 / 10);
		_putnbr(nb1 % 10);
	}
	else
		_putchar(nb1 + '0');
	return (l + 1);
}

