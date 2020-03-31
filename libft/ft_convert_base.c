/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:00:58 by calpha            #+#    #+#             */
/*   Updated: 2019/11/04 13:46:02 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		int_nbr;
	int		int_base_to;
	int		int_base_from;
	int		i;
	char	*s;

	int_base_to = 0;
	int_base_from = 0;
	i = 0;
	while (base_from[i] != '\0')
	{
		int_base_from = int_base_from * 10 + (base_from[i] - '0');
		i++;
	}
	while (*base_to != '\0')
		int_base_to = int_base_to * 10 + (*base_to++ - '0');
	if (int_base_to < 2 || int_base_to > 36 ||
			int_base_from < 2 || int_base_from > 36)
		return ("ERROR. Enter the base from 2 to 36");
	int_nbr = ft_atoi_base(nbr, base_from);
	s = ft_itoa_base(int_nbr, int_base_to);
	return (s);
}
