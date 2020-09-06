/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 00:23:18 by semen             #+#    #+#             */
/*   Updated: 2020/09/04 01:28:29 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	link_removal_a(t_num ***list_a, t_num ***list_b, t_num **list_b_tmp, t_num **tmp_tmp)
{
	t_num *next;
	t_num *prev;

	next = (**list_b)->next;
	prev = (**list_b)->prev;
	*list_b_tmp = **list_b;
	if ((**list_b)->prev != NULL)
		**list_b = (**list_b)->prev;
	(**list_b)->next = next;
	if ((**list_b)->next != NULL)
		**list_b = (**list_b)->next;
	(**list_b)->prev = prev;
	*tmp_tmp = *list_b_tmp;
	*list_b_tmp = **list_a;
	**list_a = *tmp_tmp;
}

void		pa_three(t_num ***list_a, t_num ***list_b, t_key *bonus)
{
	t_num *list_b_tmp;
	t_num *tmp_tmp;

	if (**list_b)
	{
		if (**list_a == NULL)
		{
			if ((**list_b)->next == NULL && **list_a == NULL)
			{
				**list_a = **list_b;
				**list_b = NULL;
			}
			else
			{
				link_removal_a(list_a, list_b, &list_b_tmp, &tmp_tmp);
				(**list_a)->next = NULL;
				(**list_a)->prev = NULL;
			}
		}
		else
		{
			link_removal_a(list_a, list_b, &list_b_tmp, &tmp_tmp);
			if (list_b_tmp->next == NULL)
			{
				list_b_tmp->next = **list_a;
				list_b_tmp->prev = **list_a;
				(**list_a)->next = list_b_tmp;
				(**list_a)->prev = list_b_tmp;
			}
			else
			{
				tmp_tmp = list_b_tmp;
				tmp_tmp = tmp_tmp->prev;
				(**list_a)->next = list_b_tmp;
				(**list_a)->prev = tmp_tmp;
				list_b_tmp->prev = **list_a;
				tmp_tmp->next = (**list_a);
			}
		}
		if (**list_a == **list_b)
			**list_b = NULL;
		if (bonus->print == 1)
			ft_printf("pa\n");
	}
}
