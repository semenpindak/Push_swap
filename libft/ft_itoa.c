/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 05:38:32 by calpha            #+#    #+#             */
/*   Updated: 2019/11/04 13:32:03 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	razrad(int m)
{
	int j;

	j = 0;
	while (m != 0)
	{
		j++;
		m = m / 10;
	}
	return (j);
}

char		*ft_itoa(int n)
{
	int		i;
	int		r;
	char	*s;

	i = razrad(n);
	if (!(s = n <= 0 ? ft_strnew(++i) : ft_strnew(i)))
		return (NULL);
	s[0] = n >= 0 ? '0' : '-';
	while (n != 0)
	{
		r = n < 0 ? -(n % 10) : n % 10;
		s[--i] = r + '0';
		n = n / 10;
	}
	return (s);
}
