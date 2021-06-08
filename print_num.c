/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:09:57 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/08 13:07:24 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_neg_num(char *str, int len, t_info *info)
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

static int	print_pos_num(char *str, int len, t_info *info)
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

int			print_int(int n, t_info *info)
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

int			print_uint(unsigned int n, t_info *info)
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

int			print_ptr(unsigned long long n, t_info *info)
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
