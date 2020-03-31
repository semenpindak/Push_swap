/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 14:43:20 by calpha            #+#    #+#             */
/*   Updated: 2019/10/05 10:16:36 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *tmp;

	if (!(tmp = (char *)malloc(size * sizeof(char))))
		return (NULL);
	ft_bzero(tmp, size);
	return ((void *)tmp);
}
