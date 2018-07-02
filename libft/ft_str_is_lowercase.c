/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 09:38:24 by jlobjois          #+#    #+#             */
/*   Updated: 2016/11/15 18:19:16 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_lowercase(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
	return (1);
}
