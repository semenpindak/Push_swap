/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogeonosi <ogeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:56:41 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/01/30 17:08:40 by ogeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_x_x_two(int len, int len_str, char *str, t_flag *flags)
{
	int		p;

	if (flags->space)
		len += ft_write(flags->space);
	if (flags->hash)
	{
		len += ft_write('0');
		len += ft_write(flags->spec);
	}
	p = -1;
	while (++p < flags->precision - len_str)
		len += ft_write('0');
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	p = 0;
	while (p < flags->width - flags->precision -
		(flags->space != 0) - check_hesh_x_x(flags))
	{
		len += ft_write(' ');
		p++;
	}
	free(str);
	return (len);
}

int			ft_x_x_one(int len, int len_str, char *str, t_flag *flags)
{
	int		p;

	while (len < flags->width - flags->precision -
		(flags->space != 0) - check_hesh_x_x(flags))
		len += ft_write(' ');
	if (flags->space)
		len += ft_write(flags->space);
	if (flags->hash)
	{
		len += ft_write('0');
		len += ft_write(flags->spec);
	}
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

int			ft_x_x_notdot(int len_str, char *str, t_flag *flags)
{
	int		len;

	len = 0;
	if (!flags->minus)
	{
		if (!flags->zero)
			len += ft_x_x_five(len_str, str, flags);
		else
			len += ft_x_x_six(len_str, str, flags);
	}
	else
		len += ft_x_x_seven(len_str, str, flags);
	return (len);
}

int			ft_x_x_dot(int len_str, char *str, t_flag *flags)
{
	int		len;

	len = 0;
	if (flags->precision > len_str + check_flags(flags))
	{
		if (!flags->minus)
			len += ft_x_x_one(len, len_str, str, flags);
		else
			len += ft_x_x_two(len, len_str, str, flags);
	}
	else
	{
		if (!flags->minus)
			len += ft_x_x_three(len_str, str, flags);
		else
			len += ft_x_x_four(len_str, str, flags);
	}
	return (len);
}

int			ft_x_x(long long i, t_flag *flags)
{
	int		len_str;
	char	*str;

	str = ft_lltoa_base_x_x(i, 16, check_x_x(flags));
	if (flags->dot && flags->precision == 0 && i == 0)
		*str = '\0';
	len_str = ft_strlen(str);
	return (flags->dot ? ft_x_x_dot(len_str, str, flags)
			: ft_x_x_notdot(len_str, str, flags));
}
