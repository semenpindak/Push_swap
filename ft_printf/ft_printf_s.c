/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogeonosi <ogeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:56:22 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/01/30 14:56:22 by ogeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_else(int len, int len_str, char *str, t_flag *flags)
{
	int p;

	p = 0;
	if (len_str > flags->precision)
		len_str = flags->precision;
	if (!flags->minus)
	{
		while (len < flags->width - len_str)
			len += ft_write(' ');
		while (p < len_str)
			len += ft_write(str[p++]);
	}
	else
	{
		while (len < len_str)
			len += ft_write(str[len]);
		while (p < flags->width - len_str)
		{
			len += ft_write(' ');
			p++;
		}
	}
	return (len);
}

int			ft_is(int len, int len_str, char *str, t_flag *flags)
{
	int p;

	p = 0;
	if (!flags->minus)
	{
		while (len < flags->width - len_str)
			len += ft_write(' ');
		while (p < len_str)
			len += ft_write(str[p++]);
	}
	else
	{
		while (len < len_str)
			len += ft_write(str[len]);
		while (p < flags->width - len_str)
		{
			len += ft_write(' ');
			p++;
		}
	}
	return (len);
}

int			ft_printf_s(va_list args, t_flag *flags)
{
	int		len_str;
	int		len;
	char	*str;

	len = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	len_str = ft_strlen(str);
	return (!flags->dot ? ft_is(len, len_str, str, flags)
			: ft_else(len, len_str, str, flags));
}
