/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 06:46:07 by semen             #+#    #+#             */
/*   Updated: 2020/04/16 12:51:25 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_number **list_a)
{
	if ((*list_a)->next != NULL)
	{
		*list_a = (*list_a)->next;
		ft_putstr("ra\n");
	}
}
