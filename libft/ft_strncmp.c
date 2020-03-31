/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 03:03:32 by calpha            #+#    #+#             */
/*   Updated: 2019/10/05 10:27:05 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	n--;
	while (*s1 - *s2 == 0 && *s1 != '\0' && *s2 != '\0' && n--)
	{
		s1++;
		s2++;
	}
	return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
}
