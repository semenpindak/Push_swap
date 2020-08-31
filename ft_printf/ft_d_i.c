/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogeonosi <ogeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:53:58 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/01/30 14:53:58 by ogeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_d_i_seven(int len_str, char *str, t_flag *flags)
{
	int		len;
	int		p;

	len = 0;
	if (flags->space && !flags->space_d)
		len += ft_write(flags->space);
	else if (flags->space_d)
		len += ft_write(flags->space_d);
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	p = 0;
	while (p < flags->width - len_str - (flags->space != 0))
	{
		len += ft_write(' ');
		p++;
	}
	free(str);
	return (len);
}

int			ft_d_i_six(int len_str, char *str, t_flag *flags)
{
	int		len;
	int		p;

	len = 0;
	if (flags->space && !flags->space_d)
		len += ft_write(flags->space);
	else if (flags->space_d)
		len += ft_write(flags->space_d);
	p = 0;
	while (p < flags->width - len_str - (flags->space != 0))
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

int			ft_d_i_five(int len_str, char *str, t_flag *flags)
{
	int		len;
	int		p;

	len = 0;
	p = 0;
	while (p < flags->width - len_str - check_flags(flags))
	{
		len += ft_write(' ');
		p++;
	}
	if (flags->space && !flags->space_d)
		len += ft_write(flags->space);
	else if (flags->space_d)
		len += ft_write(flags->space_d);
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	free(str);
	return (len);
}

int			ft_d_i_four(int len_str, char *str, t_flag *flags)
{
	int		p;
	int		len;

	len = 0;
	if (flags->space && !flags->space_d)
		len += ft_write(flags->space);
	else if (flags->space_d)
		len += ft_write(flags->space_d);
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	p = 0;
	while (p < flags->width - len_str - (flags->space != 0))
	{
		len += ft_write(' ');
		p++;
	}
	free(str);
	return (len);
}

int			ft_d_i_three(int len_str, char *str, t_flag *flags)
{
	int		p;
	int		len;

	len = 0;
	p = 0;
	while (p < flags->width - len_str - (flags->space != 0))
	{
		len += ft_write(' ');
		p++;
	}
	if (flags->space && !flags->space_d)
		len += ft_write(flags->space);
	else if (flags->space_d)
		len += ft_write(flags->space_d);
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	free(str);
	return (len);
}
