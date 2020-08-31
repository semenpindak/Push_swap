/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogeonosi <ogeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:56:26 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/01/30 16:54:31 by ogeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_hesh_x_x(t_flag *flags)
{
	if (flags->hash)
		return (2);
	return (0);
}

int				check_x_x(t_flag *flags)
{
	if (flags->spec == 'X')
		return (1);
	return (0);
}

char			*ft_lltoa_base_x_x(unsigned long long n, int base, int x_x)
{
	size_t		digit;
	char		*str;

	digit = (n) ? ft_countdigit(n, base, 0) : 1;
	if (!(str = (char *)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	str[digit] = '\0';
	if (x_x == 1)
		while (digit--)
		{
			str[digit] = ft_abs(n % base) + (n % base > 9 ? 'A' - 10 : '0');
			n /= base;
		}
	else
	{
		while (digit--)
		{
			str[digit] = ft_abs(n % base) + (n % base > 9 ? 'a' - 10 : '0');
			n /= base;
		}
	}
	return (str);
}

int				ft_print_x_x(va_list args, t_flag *flags)
{
	long long	i;

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
	if (flags->space == '+')
		flags->space = ' ';
	if (i == 0)
		flags->hash = 0;
	return (ft_x_x(i, flags));
}
