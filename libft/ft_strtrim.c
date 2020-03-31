/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 10:50:38 by calpha            #+#    #+#             */
/*   Updated: 2019/10/05 12:08:15 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cut(char sc)
{
	return (sc == ' ' || sc == '\n' || sc == '\t');
}

char		*ft_strtrim(char const *s)
{
	size_t start;
	size_t end;

	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (cut(s[start]))
		start++;
	if (s[start] == '\0')
		return (ft_strnew(1));
	while (cut(s[end]))
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
