/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:20:13 by calpha            #+#    #+#             */
/*   Updated: 2019/10/18 16:19:27 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == '\0')
		return (NULL);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (j + i < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char*)&haystack[i]);
				if (haystack[i + j] != needle[j])
					break ;
			}
		}
		i++;
	}
	return (NULL);
}
