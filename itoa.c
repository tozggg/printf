/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:09:53 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/09 04:26:08 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size_dec(unsigned long long n)
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

static int	get_size_hex(unsigned long long n)
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

static void	assign_str_dec(char *str, unsigned long long n, int size)
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

static void	assign_str_hex(char *str, unsigned long long n, int size, char type)
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

char		*ft_itoa(unsigned long long n, int *len, char type)
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
