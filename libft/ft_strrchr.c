/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 02:41:33 by calpha            #+#    #+#             */
/*   Updated: 2019/11/04 13:34:17 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	if (c == '\0')
		return ((char *)s);
	while (i--)
	{
		if (*--s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}
