/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:33:49 by calpha            #+#    #+#             */
/*   Updated: 2019/10/25 21:16:08 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	discharge_count(int val, int bas)
{
	int j;

	j = 0;
	while (val != 0)
	{
		val = val / bas;
		j++;
	}
	return (j);
}

char		*ft_itoa_base(int value, int base)
{
	char	*number;
	char	*s;
	size_t	i;
	int		r;

	number = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (base < 2 || base > 36)
		return ("ERROR. Enter the base from 2 to 36");
	if (value == 0)
	{
		s = ft_strnew(1);
		s[0] = '0';
	}
	i = discharge_count(value, base);
	s = base == 10 && value < 0 ? ft_strnew(++i) : ft_strnew(i);
	s[0] = base == 10 && value < 0 ? '-' : '0';
	while (value != 0)
	{
		r = value > 0 ? value % base : (value % base) * -1;
		s[--i] = (number[r] == 0 ? '0' : number[r]);
		value = value / base;
	}
	return (s);
}
