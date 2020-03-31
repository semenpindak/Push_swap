/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:05:54 by calpha            #+#    #+#             */
/*   Updated: 2020/03/01 17:06:47 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_i_to_slash_n(char *s)
{
	int k;

	k = 0;
	while (s[k] != '\0')
	{
		if (s[k] == '\n')
			break ;
		k++;
	}
	return (k);
}

static int	return_line(char *buff[FD], char *s, char **line, int a)
{
	int i;
	int j;

	if (a)
	{
		i = count_i_to_slash_n(s);
		j = 0;
		if (!(*line = ft_strsub(s, 0, i)))
			return (-1);
		while (s[i++] != '\0')
			*(*buff + j++) = s[i];
	}
	if (!a)
		if (!(*line = ft_strdup(s)))
			return (-1);
	ft_strdel(&s);
	return (1);
}

static void	del_and_clear(char **tmp, char *buff[FD])
{
	int j;

	j = 0;
	ft_strdel(tmp);
	while (*(*buff + j) != '\0')
		*(*buff + j++) = '\0';
}

int			get_next_line(const int fd, char **line)
{
	static char	*buff[FD];
	char		*s;
	char		*tmp;
	int			r;

	if (fd < 0 || fd >= FD || BUFF_SIZE < 1)
		return (-1);
	if (buff[fd] == NULL)
		buff[fd] = ft_strnew(BUFF_SIZE);
	s = ft_strdup(buff[fd]);
	ft_strclr(buff[fd]);
	if (strchr(s, '\n'))
		return (return_line(&buff[fd], s, line, 1));
	while ((r = read(fd, buff[fd], BUFF_SIZE)) > 0)
	{
		tmp = s;
		s = ft_strjoin(tmp, buff[fd]);
		del_and_clear(&tmp, &buff[fd]);
		if (strchr(s, '\n'))
			return (return_line(&buff[fd], s, line, 1));
	}
	if (!r && ft_strlen(s) != 0)
		return (return_line(&buff[fd], s, line, 0));
	ft_strdel(&s);
	return (r == -1 ? -1 : 0);
}
