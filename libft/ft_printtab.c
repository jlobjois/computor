/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 12:55:08 by jlobjois          #+#    #+#             */
/*   Updated: 2022/11/01 19:33:30 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab(char **tab, void (*f)(const char *s), char *str)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		if (tab[i] == NULL)
			return ;
		if ((f && str) && tab[i] != NULL)
			f(str);
		ft_putstr(tab[i]);
		i++;
	}
}
