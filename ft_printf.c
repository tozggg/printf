#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_info
{
	int		sign;
	int		zero;
	int		width;
	int		prec;
	char	spec;
}				t_info;

int		ft_printf(const char* format, ...)
{
	int		ret;
	va_list	ap;
	
	ret = 0;
	va_start(ap, format);
	while (*format)
	{

	}
	va_end(ap);
	return (ret);
}
