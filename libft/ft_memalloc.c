/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:25:37 by jlobjois          #+#    #+#             */
/*   Updated: 2022/11/01 18:45:53 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = (char *)malloc(sizeof(char) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
