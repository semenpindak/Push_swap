/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 03:56:36 by calpha            #+#    #+#             */
/*   Updated: 2019/10/05 10:03:14 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *sp1;
	const unsigned char *sp2;

	sp1 = s1;
	sp2 = s2;
	if (n == 0)
		return (0);
	n--;
	while (*sp1 - *sp2 == 0 && n)
	{
		sp1++;
		sp2++;
		n--;
	}
	return ((int)(*sp1 - *sp2));
}
