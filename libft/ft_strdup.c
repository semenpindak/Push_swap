/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:35:06 by calpha            #+#    #+#             */
/*   Updated: 2019/09/28 15:04:46 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*dsrc;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	if (!(dsrc = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		dsrc[i] = s1[i];
		i++;
	}
	dsrc[i] = '\0';
	return (dsrc);
}
