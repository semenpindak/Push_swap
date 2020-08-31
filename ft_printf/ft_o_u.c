/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogeonosi <ogeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:10:17 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/01/30 14:57:12 by ogeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_o_u_seven(long long i, int len_str, char *str, t_flag *flags)
{
	int			p;
	int			len;

	len = 0;
	if (flags->space)
		len += ft_write(flags->space);
	if (flags->hash && flags->spec != 'u' && i != 0)
		len += ft_write('0');
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	p = 0;
	while (p < flags->width - len_str -
	(flags->space != 0) - check_zero_hash(flags, i))
	{
		len += ft_write(' ');
		p++;
	}
	free(str);
	return (len);
}

int				ft_o_u_six(int len_str, char *str, t_flag *flags)
{
	int			p;
	int			len;

	len = 0;
	if (flags->space)
		len += ft_write(flags->space);
	p = 0;
	if (flags->hash && flags->spec != 'u')
	{
		len += ft_write('0');
		p += 1;
	}
	while (p < flags->width - len_str - (check_flags(flags)))
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

int				ft_o_u_five(long long i, int len_str, char *str, t_flag *flags)
{
	int			p;
	int			len;

	len = 0;
	p = 0;
	while (p < flags->width - len_str
			- check_flags(flags) - check_zero_hash(flags, i))
	{
		len += ft_write(' ');
		p++;
	}
	if (flags->hash && flags->spec != 'u' && i != 0)
		len += ft_write('0');
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	free(str);
	return (len);
}

int				ft_o_u_four(long long i, int len_str, char *str, t_flag *flags)
{
	int			p;
	int			len;

	len = 0;
	if (flags->space)
		len += ft_write(flags->space);
	if (flags->hash)
		len += ft_write('0');
	p = 0;
	if (i != 0)
		while (str[p])
			len += ft_write(str[p++]);
	else if (flags->precision != 0)
		len += ft_write('0');
	p = 0;
	while (p < flags->width - len_str -
	(flags->space != 0) - (flags->hash != 0))
	{
		len += ft_write(' ');
		p++;
	}
	free(str);
	return (len);
}

int				ft_o_u_three(long long i, int len_str, char *str, t_flag *flags)
{
	int			p;
	int			len;

	len = 0;
	p = 0;
	while (p < flags->width - len_str -
	(flags->space != 0) - (flags->hash != 0))
	{
		len += ft_write(' ');
		p++;
	}
	if (flags->space)
		len += ft_write(flags->space);
	if (flags->hash)
		len += ft_write('0');
	p = 0;
	if (i != 0)
		while (str[p])
			len += ft_write(str[p++]);
	else if (flags->precision != 0)
		len += ft_write('0');
	free(str);
	return (len);
}
