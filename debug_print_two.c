/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:51:48 by oem               #+#    #+#             */
/*   Updated: 2020/09/06 09:51:09 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print_two(t_num **list_a, t_num **list_b, t_key *bonus)
{
	int i;

	i = bonus->i;
	if (bonus->key == 1)
	{
		ft_printf("move = %d\n", ++i);
		show_me_two(list_a, list_b, bonus);
		// usleep(1000000);
		// system("clear");
	}
	if (bonus->key == 2)
	{
		ft_printf("move = %d\n", ++i);
		show_me_two(list_a, list_b, bonus);
		// usleep(1000000);
		// system("clear");
	}
	bonus->i = i;
}
