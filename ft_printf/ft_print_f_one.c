/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:00:51 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/02/06 17:33:39 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_len_str(char *str, t_flag *flags)
{
	int		len;
	int		k;
	int		i;

	i = 0;
	len = 0;
	k = 0;
	if (flags->space != 0)
		len += 1;
	while (str[i] != '\0')
	{
		len += 1;
		i++;
		if (str[i] == '.')
		{
			k = i;
			if (flags->precision == 0)
				break ;
		}
		if (i == k + flags->precision + 1 && k != 0)
			break ;
	}
	return (len);
}

int			ft_write_f(char *str, t_flag *flags, int k, int p)
{
	int		len;
	int		i;

	i = 0;
	len = (flags->space != 0) ? ft_write(flags->space) : 0;
	while (str[i] != '\0')
	{
		if (flags->zero != 0)
			while (p++ < (flags->width - ft_len_str(str, flags)))
				len += ft_write('0');
		len += ft_write(str[i++]);
		if (str[i] == '.')
		{
			k = i;
			if (flags->precision == 0)
			{
				len += (flags->hash) ? ft_write('.') : 0;
				break ;
			}
		}
		if (i == k + flags->precision + 1 && k != 0)
			break ;
	}
	return (len);
}

int			ft_write_f_min(char *str, t_flag *flags, int k)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (flags->space != 0)
		len += ft_write(flags->space);
	while (str[i] != '\0')
	{
		len += ft_write(str[i]);
		i++;
		if (str[i] == '.')
		{
			k = i;
			if (flags->precision == 0)
			{
				if (flags->hash)
					len += ft_write('.');
				break ;
			}
		}
		if (i == k + flags->precision + 1 && k != 0)
			break ;
	}
	return (len);
}

int			function_len_one(t_flag *flags, int k, char *str, int p)
{
	int		len;

	len = 0;
	if (!flags->minus)
	{
		if (!flags->zero)
			while (len < flags->width - ft_len_str(str, flags))
				len += ft_write(' ');
		len += ft_write_f(str, flags, k, p);
	}
	return (len);
}

int			ft_print_f_one(char *str, t_flag *flags)
{
	int		len;
	int		len_str;
	int		k;
	int		p;

	len = 0;
	len_str = 0;
	k = 0;
	p = 0;
	if (flags->precision == -1)
		flags->precision = 6;
	rounding(str, flags->precision);
	if (!flags->minus)
		len = function_len_one(flags, k, str, p);
	else
	{
		len_str += ft_write_f_min(str, flags, k);
		len += len_str;
		while (p++ < flags->width - len_str)
			len += ft_write(' ');
	}
	return (len);
}
