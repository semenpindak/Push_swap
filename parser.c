/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:56:45 by oem               #+#    #+#             */
/*   Updated: 2020/08/31 11:59:10 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parser(int ac, char *av[], int *ret)
{
	char ***arg;
	char **argw;
	int i;
	int j;
	int k;
	int a;

	if (!(arg = (char ***)malloc((ac) * sizeof(char **))))
		return (0);
	arg[ac - 1] = NULL;
	i = 0;
	j = 1;
	while (j < ac)
	{
		arg[i] = ft_strsplit(av[j], 32);
		i++;
		j++;
	}
	i = 0;
	k = 0;
	while (arg[i] != NULL)
	{
		j = 0;
		while (arg[i][j] != NULL)
			j++;
		i++;
		k += j;
	}
	if (!(argw = (char **)malloc((k) * sizeof(char *))))
		return (0);
	i = 0;
	a = 0;
	while (arg[i] != NULL)
	{
		j = 0;
		while (arg[i][j] != NULL)
		{
			argw[a] = arg[i][j];
			j++;
			a++;
		}
		i++;
	}
	*ret = k;
	return (argw);
}
