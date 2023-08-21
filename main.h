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

static int checks(va_list argp, const char *str, t_locals *loc);
int _printf(const char *format, ...);
int _putchar(char c);
int _putstr(char *s);

#endif

