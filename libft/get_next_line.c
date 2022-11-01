/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:35:03 by jlobjois          #+#    #+#             */
/*   Updated: 2022/11/01 18:39:20 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlensize(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static void	ft_read_buff(int fd, t_gnl *gnl)
{
	while ((ft_strchr(gnl->stock[fd], '\n') == 0)
			&& (gnl->read_buff = read(fd, gnl->buff, BUFF_SIZE)) > 0)
	{
		gnl->buff[gnl->read_buff] = '\0';
		gnl->tmp = gnl->stock[fd];
		gnl->stock[fd] = ft_strjoin(gnl->stock[fd], gnl->buff);
		ft_strdel(&gnl->tmp);
	}
	ft_strdel(&gnl->buff);
}

int					get_next_line(int const fd, char **line)
{
	static t_gnl	gnl;

	gnl.buff = (char *)ft_memalloc(BUFF_SIZE + 1);
	if (fd < 0 || fd > MAX_FD || BUFF_SIZE <= 0
			|| line == NULL || gnl.buff == NULL)
		return (-1);
	if (gnl.stock[fd] == NULL)
		gnl.stock[fd] = ft_strnew(1);
	ft_read_buff(fd, &gnl);
	if (gnl.read_buff == -1)
		return (-1);
	*line = ft_strsub(gnl.stock[fd], 0, ft_strlensize(gnl.stock[fd], '\n'));
	if (ft_strchr(gnl.stock[fd], '\n'))
	{
		gnl.tmp = gnl.stock[fd];
		gnl.stock[fd] = ft_strdup(ft_strchr(gnl.stock[fd], '\n') + 1);
		free(gnl.tmp);
		return (1);
	}
	if (ft_strlensize(gnl.stock[fd], '\n') > 0)
	{
		gnl.stock[fd] = gnl.stock[fd] + ft_strlensize(gnl.stock[fd], '\n');
		return (1);
	}
	return (0);
}
