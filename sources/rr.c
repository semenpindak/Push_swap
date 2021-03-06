/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 00:33:56 by semen             #+#    #+#             */
/*   Updated: 2020/10/06 15:10:43 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_num ***list_a, t_num ***list_b, t_key *bonus)
{
	if (**list_a && **list_b && (**list_a)->next != NULL
				 && (**list_b)->next != NULL)
	{
		**list_a = (**list_a)->next;
		**list_b = (**list_b)->next;
		if (bonus->print == 1)
			ft_printf("rr\n");
	}
}
