/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:05:54 by calpha            #+#    #+#             */
/*   Updated: 2020/09/06 16:04:46 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_line(char *buff, char *s, char **line, int a)
{
	int i;
	int j;

	if (a)
	{
		i = 0;
		j = 0;
		while (s[i] != '\0')
		{
			if (s[i] == '\n')
				break ;
			i++;
		}
		if (!(*line = ft_strsub(s, 0, i)))
			return (-1);
		i++;
		while (s[i] != '\0')
			buff[j++] = s[i++];
	}
	if (!a)
		if (!(*line = ft_strdup(s)))
			return (-1);
	ft_strdel(&s);
	return (1);
}

static void	del_and_clear(char **tmp, char *buff)
{
	ft_strdel(tmp);
	ft_strclr(buff);
}

t_node		*create_new_node(int fd, t_node **head)
{
	t_node *tmp;

	tmp = *head;
	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->fd = fd;
	tmp->buff = ft_strnew(BUFF_SIZE);
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}

t_node		*find_and_create_new_node(int fd, t_node **head)
{
	t_node *tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		tmp = create_new_node(fd, head);
		return (tmp);
	}
	while (tmp->next != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->next == NULL && tmp->fd != fd)
	{
		tmp = create_new_node(fd, head);
		return (tmp);
	}
	return (tmp);
}

int			get_next_line(const int fd, char **line)
{
	static t_node	*head;
	t_node			*tmp_struct;
	char			*s;
	char			*tmp;
	int				r;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	tmp_struct = find_and_create_new_node(fd, &head);
	s = tmp_struct->buff;
	if (ft_strchr(s, '\n'))
		return (return_line(tmp_struct->buff, s, line, 1));
	while ((r = read(fd, tmp_struct->buff, BUFF_SIZE)) > 0)
	{
		tmp = s;
		s = ft_strjoin(tmp, tmp_struct->buff);
		del_and_clear(&tmp, tmp_struct->buff);
		if (ft_strchr(s, '\n'))
			return (return_line(tmp_struct->buff, s, line, 1));
	}
	if (!r && ft_strlen(s) != 0)
		return (return_line(tmp_struct->buff, s, line, 0));
	ft_strdel(&s);
	free(tmp_struct);
	return (r == -1 ? -1 : 0);
}
