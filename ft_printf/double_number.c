/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:36:49 by calpha            #+#    #+#             */
/*   Updated: 2020/09/08 17:21:47 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_tmp_2(char *tmp_2, int i)
{
	int k;

	k = 0;
	while (i)
	{
		tmp_2[k] = '0';
		k++;
		i--;
	}
}

static char	*with_zero(long long int n, long long int f, int i, int sign)
{
	char			*tmp;
	char			*tmp_1;
	char			*tmp_2;
	char			*s;

	tmp = ft_itoa(n);
	tmp_1 = ft_strjoin(tmp, ".");
	s = ft_strnew(i);
	fill_tmp_2(s, i);
	tmp_2 = ft_itoa(f);
	s = ft_strjoin(s, tmp_2);
	s = ft_strjoin(tmp_1, s);
	if (sign < 0)
		s = ft_strjoin("-", s);
	return (s);
}

static char	*no_zero(long long int n, long long int f, int sign)
{
	char			*tmp;
	char			*tmp_1;
	char			*tmp_2;
	char			*s;

	tmp = ft_itoa(n);
	tmp_1 = ft_strjoin(tmp, ".");
	tmp_2 = ft_itoa(f);
	s = ft_strjoin(tmp_1, tmp_2);
	if (sign < 0)
		s = ft_strjoin("-", s);
	return (s);
}

char		*double_number(long double num)
{
	long long	n;
	long long	f;
	long double	frac;
	int			i;
	int			sign;

	n = num;
	i = 0;
	sign = 1;
	if (num < 0 && n == 0)
		sign = -1;
	frac = num - (long double)n;
	frac = frac < 0 ? -(frac) : frac;
	num = frac;
	frac = frac * 1000000000000000000;
	f = frac;
	while (i < 20)
	{
		num *= 10;
		if ((int)num == 0)
			i++;
		else
			break ;
	}
	return (i == 0 ? no_zero(n, f, sign) : with_zero(n, f, i, sign));
}
