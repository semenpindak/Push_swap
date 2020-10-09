/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 00:37:28 by semen             #+#    #+#             */
/*   Updated: 2020/10/06 15:10:43 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_num ***list_a, t_num ***list_b, t_key *bonus)
{
	if (**list_a && **list_b && (**list_a)->prev != NULL
				 && (**list_b)->prev != NULL)
	{
		**list_a = (**list_a)->prev;
		**list_b = (**list_b)->prev;
		if (bonus->print == 1)
			ft_printf("rrr\n");
	}
}
