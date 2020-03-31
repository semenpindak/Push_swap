/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 08:13:48 by nblackie          #+#    #+#             */
/*   Updated: 2019/10/07 22:09:13 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int n_words;
	int inword;

	n_words = 0;
	inword = 0;
	while (*s != '\0')
	{
		if (*s != c && !inword)
		{
			inword = 1;
			n_words++;
		}
		if (*s == c && inword)
			inword = 0;
		s++;
	}
	return (n_words);
}

static void	clear(char **aop, int i)
{
	int n;

	n = 0;
	while (i >= n)
	{
		free(aop[i]);
		i--;
	}
	free(aop);
	aop = NULL;
}

static char	**fill_string_array(char **aop, char const *s, char c, int i)
{
	int j;

	while (*s != '\0')
	{
		j = 0;
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
		{
			aop[i][j] = *s;
			j++;
			s++;
		}
		aop[i][j] = '\0';
		break ;
	}
	return (aop);
}

static char	**create_str_array(char **aop, char const *s, char c, int n_words)
{
	int i;
	int n_letters;

	i = 0;
	while (i < n_words)
	{
		n_letters = 0;
		while (*s == c)
			s++;
		while (*s != c && *s != '\0')
		{
			n_letters++;
			s++;
		}
		if (!(aop[i] = (char *)malloc((n_letters + 1) * sizeof(char))))
			clear(aop, i);
		else
		{
			s = s - n_letters;
			fill_string_array(aop, s, c, i);
			i++;
		}
		s = s + n_letters;
	}
	return (aop);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**aop;
	int		n_words;

	aop = NULL;
	n_words = 0;
	if (s)
	{
		n_words = word_count(s, c);
		if ((aop = (char **)malloc((n_words + 1) * sizeof(char *))))
		{
			aop[n_words] = NULL;
			aop = create_str_array(aop, s, c, n_words);
		}
	}
	return (aop);
}
