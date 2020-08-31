/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogeonosi <ogeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:56:02 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/01/30 17:05:25 by ogeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					check_zero_hash(t_flag *flags, long long i)
{
	if (flags->hash && i != 0)
		return (1);
	else
		return (0);
}

int					ft_o_u_two(int len_str, char *str, t_flag *flags)
{
	int				p;
	int				len;

	len = 0;
	if (flags->space)
		len += ft_write(flags->space);
	if (flags->hash)
		len += ft_write('0');
	p = 0;
	while (p < flags->precision - len_str - (flags->hash != 0))
	{
		len += ft_write('0');
		p++;
	}
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	p = 0;
	while (p < flags->width - flags->precision - (flags->space != 0))
	{
		len += ft_write(' ');
		p++;
	}
	free(str);
	return (len);
}

int					ft_o_u_one(int len_str, char *str, t_flag *flags)
{
	int				p;
	int				len;

	len = 0;
	p = 0;
	while (p < flags->width - flags->precision - (flags->space != 0))
	{
		len += ft_write(' ');
		p++;
	}
	if (flags->space)
		len += ft_write(flags->space);
	p = 0;
	while (p < flags->precision - len_str)
	{
		len += ft_write('0');
		p++;
	}
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	free(str);
	return (len);
}

int					ft_o_u(int len, long long i, char *str, t_flag *flags)
{
	int				len_str;

	len_str = ft_strlen(str);
	if (flags->space)
		flags->space = 0;
	if (flags->dot)
	{
		if (flags->precision > len_str + check_flags(flags))
			len += (!flags->minus ? ft_o_u_one(len_str, str, flags)
					: ft_o_u_two(len_str, str, flags));
		else
			len += (!flags->minus ? ft_o_u_three(i, len_str, str, flags)
					: ft_o_u_four(i, len_str, str, flags));
	}
	else
	{
		if (!flags->minus)
			len += !flags->zero ? ft_o_u_five(i, len_str, str, flags)
					: ft_o_u_six(len_str, str, flags);
		else
			len += ft_o_u_seven(i, len_str, str, flags);
	}
	return (len);
}

int					ft_printf_o_u(va_list args, t_flag *flags)
{
	long long		i;
	char			*str;
	int				len;

	len = 0;
	i = va_arg(args, long long);
	if (flags->h_flag != 0)
		i = (flags->h_flag == 1) ? (unsigned short)i
				: (unsigned char)i;
	if (flags->l_flag != 0)
	{
		if (flags->l_flag == 1)
			i = (long)i;
		else if (flags->l_flag == 2)
			i = (long long)i;
		else
			i = (unsigned int)i;
	}
	else
		i = (unsigned int)i;
	str = (flags->spec == 'o') ? ft_lltoa_base(i, 8)
			: ft_lltoa_base(i, 10);
	if (flags->dot && flags->precision == 0 && i == 0)
		*str = '\0';
	return (ft_o_u(len, i, str, flags));
}
