/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 05:16:21 by calpha            #+#    #+#             */
/*   Updated: 2020/03/25 13:50:07 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	char	*tmp_return;

	if (s1 && s2)
	{
		if (!(tmp = (char *)malloc((ft_strlen(s1)
			+ ft_strlen(s2) + 1) * sizeof(char))))
			return (NULL);
		tmp_return = tmp;
		while (*s1 != '\0')
			*tmp++ = *s1++;
		while (*s2 != '\0')
			*tmp++ = *s2++;
		*tmp = '\0';
		return (tmp_return);
	}
	return (NULL);
}
