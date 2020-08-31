/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogeonosi <ogeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:56:17 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/01/30 14:56:17 by ogeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_proc_else(int len, t_flag *flags)
{
	int		p;

	if (flags->width)
	{
		len += ft_write('%');
		p = 0;
		while (p < flags->width - 1)
		{
			len += ft_write(' ');
			p++;
		}
	}
	else
		len += ft_write('%');
	return (len);
}

int			ft_proc_if(int len, t_flag *flags)
{
	int		p;

	if (flags->width && flags->zero == 0)
	{
		p = 1;
		while (p < flags->width)
		{
			len += ft_write(' ');
			p++;
		}
		len += ft_write('%');
	}
	else
	{
		p = 1;
		while (p < flags->width)
		{
			len += ft_write('0');
			p++;
		}
		len += ft_write('%');
	}
	return (len);
}

int			ft_printf_percent(t_flag *flags)
{
	int		len;

	len = 0;
	return (!flags->minus ? ft_proc_if(len, flags)
			: ft_proc_else(len, flags));
}
