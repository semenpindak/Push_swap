/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:54:03 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/02/11 15:28:13 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_flags(t_flag *flags)
{
	if (flags->space)
		return (1);
	return (0);
}

int				ft_d_i_two(int len_str, char *str, t_flag *flags)
{
	int			len;
	int			p;

	len = 0;
	if (flags->space && !flags->space_d)
		len += ft_write(flags->space);
	else if (flags->space_d)
		len += ft_write(flags->space_d);
	p = 0;
	while (p < flags->precision - len_str)
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

int				ft_d_i_one(int len_str, char *str, t_flag *flags)
{
	int			len;
	int			p;

	len = 0;
	p = 0;
	while (p < flags->width - flags->precision - (flags->space != 0))
	{
		len += ft_write(' ');
		p++;
	}
	if (flags->space && !flags->space_d)
		len += ft_write(flags->space);
	else if (flags->space_d)
		len += ft_write(flags->space_d);
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

int				ft_d_i(char *str, t_flag *flags)
{
	int			len;
	int			len_str;

	len = 0;
	len_str = ft_strlen(str);
	if (flags->dot)
	{
		if (flags->precision > len_str)
			len += (!flags->minus ? ft_d_i_one(len_str, str, flags)
					: ft_d_i_two(len_str, str, flags));
		else
			len += (!flags->minus ? ft_d_i_three(len_str, str, flags)
					: ft_d_i_four(len_str, str, flags));
	}
	else
	{
		if (!flags->minus)
			len += (!flags->zero ? ft_d_i_five(len_str, str, flags)
					: ft_d_i_six(len_str, str, flags));
		else
			len += ft_d_i_seven(len_str, str, flags);
	}
	return (len);
}

int				ft_print_d_i(va_list args, t_flag *flags)
{
	long long	i;
	char		*str;

	i = va_arg(args, long long);
	if (flags->h_flag != 0)
		i = (flags->h_flag == 1 ? (short)i : (signed char)i);
	if (flags->l_flag != 0)
		i = (flags->l_flag == 1 ? (long)i : (long long)i);
	else
		i = (int)i;
	if (i < 0)
	{
		flags->space = '-';
		i *= -1;
	}
	str = ft_lltoa_base(i, 10);
	if (flags->dot && flags->precision == 0 && i == 0)
		*str = '\0';
	if (flags->space == '-')
		flags->space_d = 0;
	return (ft_d_i(str, flags));
}
