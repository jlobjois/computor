/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 21:12:47 by jlobjois          #+#    #+#             */
/*   Updated: 2022/11/01 19:39:01 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *s))
{
	int	i;

	i = -1;
	if (s && (*f))
	{
		while (s[++i])
			f(&s[i]);
	}
}
