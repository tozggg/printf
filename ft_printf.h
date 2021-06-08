/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:09:43 by taejkim           #+#    #+#             */
/*   Updated: 2021/06/08 13:15:21 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define TYPE "cspdiuxX%"
# define DEC_STR "0123456789"
# define HEX_STR_U "0123456789ABCDEF"
# define HEX_STR_L "0123456789abcdef"

typedef struct	s_info
{
	int		sign;
	int		zero;
	int		width;
	int		prec;
	int		prec_state;
	char	type;
}				t_info;

void	ft_free(char **ptr);
int		ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

char	*ft_itoa(unsigned long long n, int *len, char type);

int		print_char(char c, t_info *info);
int		print_str(char *str, t_info *info);

char 	*make_padding(char c, int size);

int		print_int(int n, t_info *info);
int		print_uint(unsigned int n, t_info *info);
int		print_ptr(unsigned long long n, t_info *info);

void	info_exception(t_info *info);
void	set_width_prec(char *format, va_list ap, t_info *info);
void	set_info(char *format, va_list ap, t_info *info);
void	init_info(t_info *info);

int		spec_print(va_list ap, t_info *info);
int		spec_check(char* format, va_list ap, char **next);
int		ft_printf(const char* format, ...);

#endif
