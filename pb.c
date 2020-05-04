/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 19:50:23 by semen             #+#    #+#             */
/*   Updated: 2020/04/10 23:37:19 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void link_removal_a(t_number **list_a, t_number **list_b, t_number **list_b_tmp, t_number **tmp_tmp)
{
    t_number *next;
    t_number *prev;

    next = (*list_a)->next;
    prev = (*list_a)->prev;
    *list_b_tmp = *list_a;
    *list_a = (*list_a)->prev;
    (*list_a)->next = next;
    *list_a = (*list_a)->next;
    (*list_a)->prev = prev;
    *tmp_tmp = *list_b_tmp;
    *list_b_tmp = *list_b;
    *list_b = *tmp_tmp;
}

void    pb(t_number **list_a, t_number **list_b)
{
    t_number *list_b_tmp;
    t_number *tmp_tmp;

    if (*list_a)
    {
        if (*list_b == NULL)
        {
          if ((*list_a)->next == NULL && *list_b == NULL)
            *list_b = *list_a;
          else
          {
            link_removal_a(list_a, list_b, &list_b_tmp, &tmp_tmp);
            (*list_b)->next = NULL;
            (*list_b)->prev = NULL;
          }
        }
        else
        {
          link_removal_a(list_a, list_b, &list_b_tmp, &tmp_tmp);
          if (list_b_tmp->next == NULL)
          {
            list_b_tmp->next = *list_b;
            list_b_tmp->prev = *list_b;
            (*list_b)->next = list_b_tmp;
            (*list_b)->prev = list_b_tmp;
          }
          else
          {
            tmp_tmp = list_b_tmp;
            tmp_tmp = tmp_tmp->prev;
            (*list_b)->next = list_b_tmp;
            (*list_b)->prev = tmp_tmp;
            list_b_tmp->prev = *list_b;
            tmp_tmp->next = (*list_b);
          }
        }
        if (*list_b == *list_a)
          *list_a = NULL;
        ft_putstr("pb\n");
    }
}
