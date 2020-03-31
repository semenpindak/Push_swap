/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:28:31 by calpha            #+#    #+#             */
/*   Updated: 2019/10/09 22:11:36 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dlen;
	size_t slen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (size <= dlen)
		return (size + slen);
	else
	{
		while (*dst != '\0')
		{
			dst++;
			size--;
		}
		size--;
		while (*src != '\0' && size--)
			*dst++ = *src++;
		*dst = '\0';
		return (slen + dlen);
	}
}
