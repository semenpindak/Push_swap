/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_four.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 06:27:46 by calpha            #+#    #+#             */
/*   Updated: 2020/08/18 06:28:06 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_four(t_number ****list_a)
{
	if ((***list_a)->next != NULL)
	{
		***list_a = (***list_a)->next;
		ft_putstr("ra\n");
	}
}
