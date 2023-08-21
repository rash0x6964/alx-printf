#include "main.h"

/**
 * _putstr - print string
 * @s: string
 * Return: length of string
 */
int	_putstr(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
