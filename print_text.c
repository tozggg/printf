/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:09:55 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/08 13:06:50 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(char c, t_info *info)
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

static char	*cut_str(char *str, t_info *info)
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

int			print_str(char *str, t_info *info)
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

char 		*make_padding(char c, int size)
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
