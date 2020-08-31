/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_frac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:20:51 by calpha            #+#    #+#             */
/*   Updated: 2020/01/30 14:51:58 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_frac(long long int n, int a)
{
	int				i;
	long long int	r;
	char			*s;
	char			*tmp;
	int				m;

	i = razrad(n);
	m = i;
	if (!(s = ft_strnew(i)))
		return (NULL);
	while (n != 0)
	{
		r = n < 0 ? -(n % 10) : n % 10;
		s[--i] = r + '0';
		n = n / 10;
	}
	tmp = s;
	if (!(s = ft_strsub(tmp, a, m)))
		return (NULL);
	free(tmp);
	return (s);
}
