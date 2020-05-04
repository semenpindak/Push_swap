/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 00:37:28 by semen             #+#    #+#             */
/*   Updated: 2020/04/30 12:21:58 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_three(t_number ***list_a, t_number ***list_b)
{
	if ((**list_a)->prev != NULL && (**list_b)->prev != NULL)
	{
		**list_a = (**list_a)->prev;
		**list_b = (**list_b)->prev;
		ft_putstr("rrr\n");
	}
}
