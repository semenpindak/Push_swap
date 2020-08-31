/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inti_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogeonosi <ogeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:42 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/01/30 15:03:56 by ogeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check(const char *str, int i)
{
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'o'
		|| str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
		|| str[i] == 'f' || str[i] == 'c' || str[i] == 's'
		|| str[i] == 'p' || str[i] == '%' || str[i] == 'b')
		return (1);
	else
		return (0);
}

int				ft_init_num(const char *str, int i, t_flag *flags)
{
	if (str[i] == '.')
		flags->dot = 1;
	else if (str[i] == '0')
		if (flags->dot == 1)
			flags->precision = 0;
		else
			flags->zero = 1;
	else
	{
		if (flags->dot == 1)
		{
			flags->precision = ft_atoi_pres(str, i);
			return (razrad(flags->precision));
		}
		else
		{
			flags->width = ft_atoi_pres(str, i);
			return (razrad(flags->width));
		}
	}
	return (1);
}

static void		ft_init_flags(const char *str, int i, t_flag *flags)
{
	if (str[i] == '#')
		flags->hash = 1;
	if (str[i] == '-')
		flags->minus = 1;
	if (str[i] == ' ' && !flags->space)
		flags->space = ' ';
	if (str[i] == '+')
	{
		flags->space = '+';
		flags->space_d = '+';
	}
	if (str[i] == 'h')
		flags->h_flag += 1;
	if (str[i] == 'l' && flags->l_flag < 2)
		flags->l_flag += 1;
	if (str[i] == 'L')
		flags->l_flag = 3;
}

void			init_star(t_flag *flags, va_list args)
{
	int			i;

	i = va_arg(args, int);
	if (i < 0)
	{
		flags->minus = 1;
		i *= -1;
	}
	if (!flags->dot)
		flags->width = i;
	else
		flags->precision = i;
}

int				ft_analazer_flags(const char *str, int i,
									t_flag *flags, va_list args)
{
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '-' || str[i] == '+'
			|| str[i] == '#' || str[i] == 'h'
			|| str[i] == 'l' || str[i] == 'L')
		{
			ft_init_flags(str, i, flags);
			i++;
		}
		else if (str[i] == '*')
		{
			init_star(flags, args);
			i++;
		}
		else if (str[i] == '.' || (str[i] >= '0' && str[i] <= '9'))
			i += ft_init_num(str, i, flags);
		else if (check(str, i) == 1)
		{
			ft_init_spec(str[i], args, flags);
			return (i);
		}
		else
			i++;
	}
	return (0);
}
