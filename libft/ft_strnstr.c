/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:53:44 by jlobjois          #+#    #+#             */
/*   Updated: 2022/11/01 17:40:11 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] && i < (int)len)
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && (i + j) < (int)len)
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
