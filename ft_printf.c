#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define TYPE "cspdiuxX%"
#define DEC_STR "0123456789"
#define HEX_STR_U "0123456789ABCDEF"
#define HEX_STR_L "0123456789abcdef"

typedef struct	s_info
{
	int		sign;
	int		zero;
	int		width;
	int		prec;
	int		prec_state;
	char	type;
}				t_info;

void	ft_free(char **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	else
	{
		free(*ptr);
		*ptr = NULL;
	}
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int		ft_putstr(char *str)
{
	int len;

	len = ft_strlen(str);
	return (write(1, str, len));
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	len;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
		return ((s1 != NULL) ? s1 : s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		ptr[i++] = s1[j];
	j = -1;
	while (s2[++j])
		ptr[i++] = s2[j];
	ptr[i] = 0;
	ft_free(&s1);
	ft_free(&s2);
	return (ptr);
}

// ---------------------------------------------------------------------------------------------------- Libft




int		get_size_dec(unsigned long long n)
{
	int		ret;
	
	if (n == 0)
		return (1);
	ret = 0;
	while (n > 0)
	{
		n /= 10;
		++ret;
	}
	return (ret);
}

int		get_size_hex(unsigned long long n)
{
	int		ret;
	
	if (n == 0)
		return (1);
	ret = 0;
	while (n > 0)
	{
		n /= 16;
		++ret;
	}
	return (ret);
}

void	assign_str_dec(char *str, unsigned long long n, int size)
{
	unsigned long long tmp;

	str[size] = 0;
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	tmp = n;
	while (tmp > 0)
	{
		str[--size] = DEC_STR[tmp % 10];
		tmp /= 10;
	}
}

void	assign_str_hex(char *str, unsigned long long n, int size, char type)
{
	unsigned long long tmp;

	str[size] = 0;
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	tmp = n;
	while (tmp > 0)
	{
		if (type == 'x' || type == 'p')
			str[--size] = HEX_STR_L[tmp % 16];
		else if (type == 'X')
			str[--size] = HEX_STR_U[tmp % 16];
		tmp /= 16;
	}
}

char	*ft_itoa(unsigned long long n, int *len, char type)
{
	char	*ret;
	int		size;

	if (type == 'i' || type == 'd' || type == 'u')
		size = get_size_dec(n);
	else if (type == 'x' || type == 'X' || type == 'p')
		size = get_size_hex(n);
	if (!(ret = (char *)malloc(sizeof(size + 1))))
	{
		*len = 0;
		return (NULL);
	}
	if (type == 'i' || type == 'd' || type == 'u')
		assign_str_dec(ret, n, size);	
	else if (type == 'x' || type == 'X' || type == 'p')
		assign_str_hex(ret, n, size, type);
	*len = size;
	return (ret);
}

//-----------------------------------------------------------------------------------------  itoa


void	init_info(t_info *info)
{
	info->sign = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = 0;
	info->prec_state = -1;
	info->type = 0;
}

int		print_char(char c, t_info *info)
{
	int		ret;
	int		i;

	ret = 0;
	if (info->sign == 1)
		ret += ft_putchar(c);
	i = 0;
	while (++i < info->width)
	{
		if (info->zero == 0)
			ret += ft_putchar(' ');
		else if (info->zero == 1)
			ret += ft_putchar('0');
	}	
	if (info->sign == 0)
		ret += ft_putchar(c);
	return (ret);
}

char	*cut_str(char *str, t_info *info)
{
	char* 	ret;
	int		len;
	int		i;

	len = ft_strlen(str);
	if (info->prec_state != -1 && info->prec < len)
		len = info->prec;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		++i;
	}
	ret[i] = 0;
	return (ret);
}

int		print_str(char *str, t_info *info)
{
	int		ret;
	int		len;

	ret = 0;
	str = cut_str(str, info);
	len = ft_strlen(str);
	if (info->sign == 1)
		ret += ft_putstr(str);
	while (++len <= info->width)
	{
		if (info->zero == 0)
			ret += ft_putchar(' ');
		else if (info->zero == 1)
			ret += ft_putchar('0');
	}
	if (info->sign == 0)
		ret += ft_putstr(str);
	ft_free(&str);
	return (ret);
}

char 	*make_padding(char c, int size)
{
	char	*ret;
	int		i;

	if (size < 0)
		size = 0;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size)
	{
		ret[i] = c;
		++i;
	}
	ret[i] = 0;
	return (ret);
}

int		print_neg_num(char *str, int len, t_info *info)
{
	int		ret;

	ret = 0;
	if (info->zero == 1)
	{
		ret += ft_putchar('-');
		str = ft_strjoin(make_padding('0', info->width - (len + 1)), str);
		ret += ft_putstr(str);
	}
	else
	{
		if (info->prec_state != -1)
		{
			str = ft_strjoin(make_padding('0', info->prec - len), str);
			len = ft_strlen(str);
		}
		str = ft_strjoin("-", str);
		if (info->sign == 1)
			str = ft_strjoin(str, make_padding(' ', info->width - (len + 1)));
		else
			str = ft_strjoin(make_padding(' ', info->width - (len + 1)), str);
		ret += ft_putstr(str);
	}
	ft_free(&str);
	return (ret);
}

int		print_pos_num(char *str, int len, t_info *info)
{
	int		ret;

	ret = 0;
	if (info->zero == 1)
	{
		str = ft_strjoin(make_padding('0', info->width - len), str);
		ret += ft_putstr(str);
	}
	else
	{
		if (info->prec_state != -1)
		{
			str = ft_strjoin(make_padding('0', info->prec - len), str);
			len = ft_strlen(str);
		}
		if (info->sign == 1)
			str = ft_strjoin(str, make_padding(' ', info->width - len));
		else
			str = ft_strjoin(make_padding(' ', info->width - len), str);
		ret += ft_putstr(str);
	}
	ft_free(&str);
	return (ret);
}

int		print_int(int n, t_info *info)
{
	int		ret;
	char	*str;
	int		len;

	ret = 0;
	len = 0;
	if (n == 0 && info->prec_state == 0)
		return (ret);
	else if (n < 0)
	{
		str = ft_itoa((unsigned long long)(n * -1), &len, info->type);
		ret += print_neg_num(str, len, info); 
	}
	else
	{
		str = ft_itoa((unsigned long long)n, &len, info->type);	
		ret += print_pos_num(str, len, info);
	}
	return (ret);
}

int		print_uint(unsigned int n, t_info *info)
{
	int		ret;
	char	*str;
	int		len;

	ret = 0;
	len = 0;
	if (n == 0 && info->prec_state == 0)
		return (ret);
	else
	{
		str = ft_itoa((unsigned long long)n, &len, info->type);
		ret += print_pos_num(str, len, info);
	}
	return (ret);
}

int		print_ptr(unsigned long long n, t_info *info)
{
	int		ret;
	char	*str;
	int		len;

	ret = 0;
	len = 0;
	ret += ft_putstr("0x");
	if (n == 0 && info->prec_state == 0)
		return (ret);
	else
	{
		str = ft_itoa((unsigned long long)n, &len, info->type);
		ret += print_pos_num(str, len, info);
	}
	return (ret);
}

int		spec_print(va_list ap, t_info *info)
{
	int		ret;
	char 	type;

	ret = -1;
	type = info->type;
	if (type == '%')
		ret = print_char('%', info);
	else if (type == 'c')
		ret = print_char(va_arg(ap, int), info);
	else if (type == 's')
		ret = print_str(va_arg(ap, char*), info);
	else if (type == 'd' || type == 'i')
		ret = print_int(va_arg(ap, int), info);
	else if (type == 'u' || type == 'x' || type == 'X')
		ret = print_uint(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		ret = print_ptr(va_arg(ap, unsigned long long), info);
	return (ret);
}

void	info_exception(t_info *info)
{
	if (info->sign == 1 && info->zero == 1)
		info->zero = 0;
	if (info->prec_state != -1 && info->zero == 1)
	{
		if (info->type != '%' && info->type != 'c' && info->type != 's')
			info->zero = 0;
	}
}

void	set_width(char *format, va_list ap, t_info *info)
{
	if (*format == '*')
	{
		if ((info->width = va_arg(ap, int)) < 0)
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
			info->width = *format - '0'; 	
	}
}

void	set_prec(char *format, va_list ap, t_info *info)
{
	if (*format == '*' && info->prec_state == 0)
	{
		if ((info->prec = va_arg(ap, int)) < 0)
		{
			info->sign = 1;
			info->prec_state = -1;
		}
	}
	if (ft_isdigit(*format))
	{
		if (ft_isdigit(*(format - 1)))
			info->prec = (info->prec * 10) + (*format - '0');
		else if (info->prec_state == 0)
			info->prec = *format - '0';
	}
	info->prec_state = 1;
}

void	set_width_prec(char *format, va_list ap, t_info *info)
{
	if (info->prec_state == -1)
		set_width(format, ap, info);
	else
		set_prec(format, ap, info);
}

void	set_info(char *format, va_list ap, t_info *info)
{
	if (*format == '-')
	{
		info->sign = 1;
		if (info->prec_state != -1)
			info->prec_state = -1;
	}
	else if (*format == '0' && info->width == 0 && info->prec_state == -1)
		info->zero = 1;
	else if (*format == '.')
		info->prec_state = 0;
	else if (ft_isdigit(*format) || *format == '*')
		set_width_prec(format, ap, info);
}

int		spec_check(char* format, va_list ap, char **next)
{
	int		ret;
	t_info	*info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	init_info(info);
	while (*format)
	{	
		if (ft_strchr(TYPE, *format))
		{
			info->type = *format;
			info_exception(info);
			ret = spec_print(ap, info);
			free(info);
			*next = format + 1;
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
	char	*next;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			spec_print = spec_check((char *)format, ap, &next);
			if (spec_print != -1)
			{
				ret += spec_print;
				format = next;
			}
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

#include <stdio.h>

int		main ()
{
	char c = 'c';
	int n = 654321;
	char *str = "apple";
	void *ptr = malloc(1);

	printf("%10d\n", n);
	int d = ft_printf("%10d\n", n);
	printf("%d\n", d);
	ft_printf("===============\n");

	printf("%010p\n", ptr);
	ft_printf("%010p\n", ptr);
	ft_printf("===============\n");

	printf("%10.4s\n", str);
	ft_printf("%10.4s\n", str);
	ft_printf("===============\n");

	printf("%10.7d\n", n);
	ft_printf("%10.7d\n", n);
	ft_printf("===============\n");

	printf("%-10.7d\n", n);
	ft_printf("%-10.7d\n", n);
	ft_printf("===============\n");

	printf("%0*.*d\n", 10, 7, n);
	ft_printf("%0*.*d\n", 10, 7, n);
	ft_printf("===============\n");

	printf("%10.-7d\n", n);
	ft_printf("%10.-7d\n", n);
	ft_printf("===============\n");


	return 0;
}
