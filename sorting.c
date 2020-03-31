/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 14:26:34 by semen             #+#    #+#             */
/*   Updated: 2020/03/31 14:33:11 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sorting(int ac, char *av[])
{
	int i;
	int j;
	int *fill_int;

	i = 0;
	j = 1;
	if (!(fill_int = (int *)malloc(sizeof(int) * (ac - 1))))
		exit(0);
	while (j < ac)
	{
		fill_int[i] = ft_atoi(av[j]);
		j++;
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		printf("%d\n", fill_int[i]);
		i++;
	}
}
