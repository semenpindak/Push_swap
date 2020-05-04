/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 07:15:23 by semen             #+#    #+#             */
/*   Updated: 2020/04/11 08:40:03 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count(t_number *list_a)
{
	int n;
	int m;

	n = 0;
	if (list_a)
	{
		m = list_a->n;
		n++;
		if(list_a->next)
			list_a = list_a->next;
		else
			return(1);
		while (list_a)
		{
			if (list_a->n != m)
				list_a = list_a->next;
			else
				break;
			n++;
		}
		return(n);
	}
	return (0);
}

void	show_me(t_number *list_a, t_number *list_b)
{
	int n;

	n = count(list_a);
	printf("stack_a: ");
    while (n--)
    {
        if (list_a)
        {
            printf("%d ", list_a->n);
            list_a = list_a->next;
        }
        else
            break;
    }
    printf("\n");
    printf("stack_b: ");
    n = count(list_b);
    while (n--)
    {
        if (list_b)
        {
            printf("%d ", list_b->n);
            list_b = list_b->next;
        }
        else
            break;
    }
    printf("\n");
}
