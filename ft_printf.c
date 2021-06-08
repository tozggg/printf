/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:09:47 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/09 04:25:19 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->sign = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = 0;
	info->prec_state = -1;
	info->type = 0;
}

int		spec_print(va_list ap, t_info *info)
{
	int		ret;
	char	type;

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

int		spec_check(char *format, va_list ap, char **next)
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

int		ft_printf(const char *format, ...)
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
			ret += ft_putchar(*(format++));
	}
	va_end(ap);
	return (ret);
}
