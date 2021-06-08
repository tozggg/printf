/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:09:38 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/08 13:00:37 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		ft_strlen(const char *s)
{
	int i;

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
