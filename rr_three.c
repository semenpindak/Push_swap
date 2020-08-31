/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 00:33:56 by semen             #+#    #+#             */
/*   Updated: 2020/08/29 14:44:34 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_three(t_number ***list_a, t_number ***list_b)
{
	if ((**list_a)->next != NULL && (**list_b)->next != NULL)
	{
		**list_a = (**list_a)->next;
		**list_b = (**list_b)->next;
		ft_printf("rr\n");
	}
}
