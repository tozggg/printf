#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define TYPE "cspdiuxX%"

typedef struct	s_info
{
	int		sign;
	int		zero;
	int		width;
	int		prec;
	char	type;
}				t_info;



int		ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int		ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		++i;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}

//----------------------------------------------------------------------------------------- libft


void	init_info(t_info *info)
{
	info->sign = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->type = 0;
}

int		spec_print(va_list ap, t_info *info)
{
	int		ret;
	char 	type;

	ret = -1;
	type = info->type;
	if (type == '%')
	else if (type == 'c')
	else if (type == 's')
	else if (type == 'd' || type == 'i')
	else if (type == 'u' || type == 'x' || type == 'X')
	else if (type == 'p')

	return (ret);
}

void	info_exception(t_info *info)
{
	if (info->sign == 1 && info->zero == 1)
		info->zero = 0;
	if (info->prec >= 0 && info->zero == 1)
	{
		if (info->type != '%')
			info->zero = 0;
	}
}

void	set_width(char *format, va_list ap, t_info *info)
{
	if (*format == '*')
	{
		if (info->width = va_arg(ap, int) < 0)
		{
			info->sign = 1;
			info->width *= -1;
		}
	}
	else if (ft_isdigit(*format))
	{
		if (ft_isdigit(*(format - 1)))
			info->width = (info->width * 10) + (*format - '0');
		else
			info->width = *format; 	
	}
}

void	set_prec(char *format, va_list ap, t_info *info)
{
	//// 여기 다시짜야됨 ... prec 예외처리 어떻게?
	if (*format == '*' && *(format - 1) == '.')
	{
		if (info->prec = va_arg(ap, int) < 0)
		{
			info->sign = 1;
			info->prec = -1;
		}
	}
	else if (ft_isdigit(*format))
	{
		if (ft_isdigit(*(format - 1)))
			info->prec = (info->prec * 10) + (*format - '0');
		else if (*(format - 1) == '.')
			info->prec = *format;
	}
}

void	set_width_prec(char *format, va_list ap, t_info *info)
{
	if (info->prec == -1)
		set_width(format, ap, info);
	else
		set_prec(format, ap, info);
}

void	set_info(char *format, va_list ap, t_info *info)
{
	if (*format == '-')
	{
		info->sign = 1;
		if (info->prec >= 0)
			info->prec = -1;
	}
	else if (*format == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (*format == '.')
		info->prec = 0;
	else if (ft_isdigit(*format) || *format == '*')
		set_width_prec(format, ap, info);
}

int		spec_check(char** ptr, va_list ap)
{
	int		ret;
	char	*format;
	t_info	*info;

	// 여기 malloc 에러처리 어떻게?
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	init_info(info);
	format = *ptr;	
	while (*format)
	{	
		if (ft_strchr(TYPE, *format))
		{
			info->type = *format;
			info_exception(info);
			ret = spec_print(ap, info);
			*ptr = format + 1;
			free(info);
			return (ret);
		}
		else 
			set_info(format, ap, info);
		++format;	
	}
	free(info);
	return (-1);
}

int		ft_printf(const char* format, ...)
{
	int		ret;
	int		spec_print;
	va_list	ap;
	
	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			spec_print = spec_check(&format, ap);
			if (spec_print != -1)
				ret += spec_print;
		}
		else
		{
			ret += ft_putchar(*format);
			++format;
		}
	}
	va_end(ap);
	return (ret);
}
