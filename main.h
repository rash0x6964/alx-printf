#ifndef MAIN_H
# define MAIN_H

# include<stdarg.h>
# include<unistd.h>

/**
 *struct s_locals - New data type as t_locals
 *@i: index of while
 *@glen: length of string i printed
 */
typedef struct s_locals
{
	int i;
	int glen;
} t_locals;

int _printf(const char *format, ...);
int _putchar(char c);
int _putstr(char *s);
int _putnbr(int nb);
void _putbinary(unsigned int n, int *len);

#endif

