/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 00:21:16 by oem               #+#    #+#             */
/*   Updated: 2020/09/01 00:26:13 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_checker(t_number **list_b)
{
	if ((*list_b)->next != NULL)
	{
		*list_b = (*list_b)->next;
	}
}
