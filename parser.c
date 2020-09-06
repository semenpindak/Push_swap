/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:56:45 by oem               #+#    #+#             */
/*   Updated: 2020/09/05 23:03:49 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**creating an array for combining arrays of type *av[]
*/

static void clear_array(char ***arg)
{
	int i;

	i = 0;
	while (arg[i] != NULL)
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

static char	***create_main_array(int ac, char *av[])
{
	char	***arg;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!(arg = (char ***)malloc((ac) * sizeof(char **))))
		return (0);
	arg[ac - 1] = NULL;
	while (j < ac)
	{
		arg[i] = ft_strsplit(av[j], 32);
		i++;
		j++;
	}
	return (arg);
}

static void	count_subarray_links(char ***arg, int *ret)
{
	int i;
	int j;

	i = 0;
	j = 0;
	*ret = 0;
	while (arg[i] != NULL)
	{
		j = 0;
		while (arg[i][j] != NULL)
			j++;
		i++;
		*ret += j;
	}
}

char		**parser(int ac, char *av[], int *ret)
{
	char	***arg;
	char	**argw;
	int		i;
	int		j;
	int		a;

	if (!(arg = create_main_array(ac, av)))
		return (0);
	count_subarray_links(arg, ret);
	if (*ret == 0)
		argw = NULL;
	else
		if (!(argw = (char **)malloc((*ret) * sizeof(char *))))
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
	*ret = a;
	clear_array(arg);
	return (argw);
}
