/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:40:10 by calpha            #+#    #+#             */
/*   Updated: 2020/02/11 19:25:21 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_rounding(char *s, int i)
{
	if (s[i] >= '5')
		return (1);
	return (0);
}

int		check_number(char *s, int i)
{
	if (s[i] == '9')
		return (1);
	return (0);
}

int		count_value_to_dot(char *s)
{
	int j;

	j = 0;
	while (s[j] != '.')
		j++;
	return (j);
}

char	*add_string(char *s)
{
	char		*tmp;
	char		*tmp_1;

	tmp = ft_strnew(1);
	tmp[0] = '1';
	tmp_1 = ft_strjoin(tmp, s);
	free(s);
	return (tmp_1);
}

char	*rounding(char *s, int n)
{
	int			i;
	int			flag;

	i = count_value_to_dot(s) + n + 1;
	if (check_rounding(s, i) == 1)
	{
		i--;
		while (i != -1)
		{
			flag = check_number(s, i);
			if (flag == 0)
				return (flag_null(s, i));
			if (flag == 1)
				s[i] = '0';
			if (i == 0)
				s = add_string(s);
			i--;
			if (s[i] == '.')
				i--;
		}
	}
	return (s);
}
