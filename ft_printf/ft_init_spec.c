/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:50:21 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/02/11 15:18:05 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf_b(va_list args, t_flag *flags)
{
	long long		i;
	char			*str;
	int				len;

	len = 0;
	i = va_arg(args, long long);
	if (flags->h_flag != 0)
		i = (flags->h_flag == 1) ? (unsigned short)i
				: (unsigned char)i;
	if (flags->l_flag != 0)
	{
		if (flags->l_flag == 1)
			i = (long)i;
		else if (flags->l_flag == 2)
			i = (long long)i;
		else
			i = (unsigned int)i;
	}
	else
		i = (unsigned int)i;
	str = ft_lltoa_base(i, 2);
	if (flags->dot && flags->precision == 0 && i == 0)
		*str = '\0';
	return (ft_o_u(len, i, str, flags));
}

int					ft_init_spec(char spec, va_list args, t_flag *flags)
{
	int				len;

	len = 0;
	flags->spec = spec;
	if (spec == 'd' || spec == 'i')
		len += ft_print_d_i(args, flags);
	else if (spec == 'o' || spec == 'u')
		len += ft_printf_o_u(args, flags);
	else if (spec == 'X' || spec == 'x')
		len += ft_print_x_x(args, flags);
	else if (spec == 'f')
		len += ft_print_f(args, flags);
	else if (spec == 'c')
		len += ft_printf_c(args, flags);
	else if (spec == 's')
		len += ft_printf_s(args, flags);
	else if (spec == 'p')
		len += ft_printf_p(args, flags);
	else if (spec == '%')
		len += ft_printf_percent(flags);
	else if (spec == 'b')
		len += ft_printf_b(args, flags);
	flags->len += len;
	return (len);
}
