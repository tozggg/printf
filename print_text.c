/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:09:55 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/09 10:29:36 by taejkim          ###   ########.fr       */
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

int			print_str(char *str, t_info *info)
{
	int		ret;
	int		len;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	if ((str = cut_str(str, info)) == NULL)
		return (0);
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
