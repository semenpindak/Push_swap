/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:09:54 by calpha            #+#    #+#             */
/*   Updated: 2020/08/14 13:58:28 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
	t_number *list_a;
	t_number *list_b;

	list_b = NULL;
	if (validation(ac, av) == 0)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	list_a = create_stack_a(ac, av);
	timsort(list_a, list_b);
	return (0);
}
