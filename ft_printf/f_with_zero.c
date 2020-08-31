/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_with_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:19:17 by calpha            #+#    #+#             */
/*   Updated: 2020/01/30 16:03:08 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_tmp_2(char *tmp_2, int i)
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

char	*f_with_zero(int sign, long long int n, double num, int i)
{
	int		razrad_int;
	char	*tmp;
	char	*tmp_1;
	char	*s;

	razrad_int = 0;
	tmp = ft_itoa_c(n, &razrad_int);
	tmp_1 = ft_strjoin(tmp, ".");
	free(tmp);
	s = ft_strnew(i);
	fill_tmp_2(s, i);
	tmp = ft_strjoin(tmp_1, s);
	free(tmp_1);
	free(s);
	tmp_1 = ft_itoa_frac(num, razrad_int);
	s = ft_strjoin(tmp, tmp_1);
	free(tmp);
	free(tmp_1);
	if (sign == -1)
	{
		tmp = s;
		s = ft_strjoin("-", tmp);
		free(tmp);
	}
	return (s);
}
