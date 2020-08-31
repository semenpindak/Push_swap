/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogeonosi <ogeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:56:08 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/01/30 16:39:10 by ogeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							ft_ifelse(char *zerox, int len_str,
							char *str, t_flag *flags)
{
	int						len;
	int						p;

	len = 0;
	p = 0;
	while (len < flags->width - len_str - 2)
		len += ft_write(' ');
	while (zerox[p])
		len += ft_write(zerox[p++]);
	p = 0;
	while (p++ < flags->precision - len_str)
		len += ft_write('0');
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	return (len);
}

int							ft_p_if(char *zerox, int len_str,
							char *str, t_flag *flags)
{
	int						len;
	int						p;

	len = 0;
	p = 0;
	if (!flags->width)
	{
		while (zerox[len])
			len += ft_write(zerox[len]);
		while (p++ < flags->precision - len_str)
			len += ft_write('0');
		p = 0;
		while (str[p])
			len += ft_write(str[p++]);
	}
	else
		len += ft_ifelse(zerox, len_str, str, flags);
	free(str);
	return (len);
}

int							ft_p_else(char *zerox, int len_str,
							char *str, t_flag *flags)
{
	int						len;
	int						p;

	len = 0;
	p = 0;
	if (!flags->width)
	{
		while (zerox[len])
			len += ft_write(zerox[len]);
		while (str[p])
			len += ft_write(str[p++]);
	}
	else
	{
		while (zerox[len])
			len += ft_write(zerox[len]);
		while (str[p])
			len += ft_write(str[p++]);
		p = 0;
		while (p++ < flags->width - len_str - 2)
			len += ft_write(' ');
	}
	free(str);
	return (len);
}

int							ft_printf_p(va_list args, t_flag *flags)
{
	int						len_str;
	int						len;
	unsigned long long		i;
	char					*str;
	char					*zerox;

	len = 0;
	zerox = "0x";
	i = va_arg(args, unsigned long long);
	if (flags->dot && flags->precision == 0 && i == 0)
	{
		while (zerox[len])
			len += ft_write(zerox[len]);
		return (len);
	}
	str = ft_lltoa_base_x_x(i, 16, 0);
	len_str = ft_strlen(str);
	return (!flags->minus ? ft_p_if(zerox, len_str, str, flags)
			: ft_p_else(zerox, len_str, str, flags));
}
