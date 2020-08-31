/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:20:13 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/08/31 21:34:21 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_error(long double nb)
{
	if (nb != nb)
		return (1);
	else if (nb == 1.0 / 0.0)
		return (2);
	else if (nb == -1.0 / 0.0)
		return (3);
	return (0);
}

int					print_error(char *str, int ret)
{
	int len;
	int i;

	len = 0;
	i = 0;
	if (ret == 1)
		str = ft_strdup("nan");
	else if (ret == 2)
		str = ft_strdup("inf");
	else
		str = ft_strdup("-inf");
	while (str[i])
	{
		len += ft_write(str[i]);
		i++;
	}
	return (len);
}

int					ft_print_f(va_list args, t_flag *flags)
{
	long double		num;
	char			*str;
	int				len;
	int				ret;

	len = 0;
	flags->precision = (flags->precision == 100) ? 6 : flags->precision;
	num = (flags->l_flag <= 2) ? va_arg(args, double)
			: va_arg(args, long double);
	ret = ft_error(num);
	if (num < 0)
	{
		flags->space = '-';
		num *= -1;
	}
	str = double_number(num);
	if (ret > 0)
	{
		len += print_error(str, ret);
		return (len);
	}
	len += ft_print_f_one(str, flags);
	free(str);
	return (len);
}
