/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 02:04:52 by calpha            #+#    #+#             */
/*   Updated: 2019/10/05 10:37:54 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while ((needle[j] != '\0') && needle[j] == haystack[i])
		{
			i++;
			j++;
		}
		if (needle[j] != '\0')
		{
			i = i - j + 1;
			j = 0;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i - j]);
	}
	return (NULL);
}
