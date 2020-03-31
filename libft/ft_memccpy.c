/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:25:42 by calpha            #+#    #+#             */
/*   Updated: 2019/10/05 10:02:00 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		if (*s == (unsigned char)c)
		{
			*(d++) = *(s++);
			return ((void *)d);
		}
		*(d++) = *(s++);
	}
	return (NULL);
}
