/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 09:13:53 by jlobjois          #+#    #+#             */
/*   Updated: 2022/11/01 17:40:27 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j])
			{
				if (little[j + 1] == '\0')
					return ((char *)(big + i));
				j++;
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}
