/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 04:03:44 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/09 04:31:31 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cut_str(char *str, t_info *info)
{
	char	*ret;
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

char	*make_padding(char c, int size)
{
	char	*ret;
	int		i;

	if (size < 0)
		size = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = c;
		++i;
	}
	ret[i] = 0;
	return (ret);
}

char	*make_0x(void)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * 3)))
		return (NULL);
	ret[0] = '0';
	ret[1] = 'x';
	ret[2] = 0;
	return (ret);
}
