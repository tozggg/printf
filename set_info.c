/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:10:03 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/08 13:09:45 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		info_exception(t_info *info)
{
	if (info->sign == 1 && info->zero == 1)
		info->zero = 0;
	if (info->prec_state != -1 && info->zero == 1)
	{
		if (info->type != '%' && info->type != 'c' && info->type != 's')
			info->zero = 0;
	}
}

static void	set_width(char *format, va_list ap, t_info *info)
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

static void	set_prec(char *format, va_list ap, t_info *info)
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

void		set_width_prec(char *format, va_list ap, t_info *info)
{
	if (info->prec_state == -1)
		set_width(format, ap, info);
	else
		set_prec(format, ap, info);
}

void		set_info(char *format, va_list ap, t_info *info)
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
