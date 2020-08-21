/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 06:41:04 by calpha            #+#    #+#             */
/*   Updated: 2020/08/18 06:45:03 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count(t_number ***list_a)
{
	int n;
	int m;

	n = 0;
	if (**list_a)
	{
		m = (**list_a)->n;
		n++;
		if((**list_a)->next)
			**list_a = (**list_a)->next;
		else
			return(n);
		while (**list_a)
		{
			if ((**list_a)->n != m)
				(**list_a) = (**list_a)->next;
			else
				break;
			n++;
		}
		return(n);
	}
	return (0);
}

void	show_me_three(t_number ***list_a, t_number ***list_b)
{
	int n;


	n = count(list_a);
	printf("n = %d ", n);

	printf("stack_a: ");
    while (n--)
    {
        if (**list_a)
        {
            printf("%d ", (**list_a)->n);
			if ((**list_a)->next != NULL)
            	**list_a = (**list_a)->next;
        }
        else
            break;
    }
    printf("\n");



    n = count(list_b);
	printf("n = %d ", n);
	printf("stack_b: ");
    while (n--)
    {
        if (**list_b)
        {
            printf("%d ", (**list_b)->n);
			if ((**list_b)->next != NULL)
            	**list_b = (**list_b)->next;
        }
        else
            break;
    }
    printf("\n");
}
