/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 00:35:29 by semen             #+#    #+#             */
/*   Updated: 2020/08/29 14:44:43 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_three(t_number ***list_a)
{
	if ((**list_a)->prev != NULL)
	{
		**list_a = (**list_a)->prev;
		ft_printf("rra\n");
	}
}
