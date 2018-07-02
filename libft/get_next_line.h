/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:49:14 by jlobjois          #+#    #+#             */
/*   Updated: 2017/05/09 13:49:17 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 42
# define MAX_FD 10240

typedef struct				s_gnl
{
	char			*stock[MAX_FD + 1];
	char			*buff;
	char			*tmp;
	int				read_buff;
}							t_gnl;

int							get_next_line(int const fd, char **line);

#endif
