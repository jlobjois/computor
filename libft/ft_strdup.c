/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:19:56 by jlobjois          #+#    #+#             */
/*   Updated: 2016/11/15 22:42:52 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	temp = malloc(sizeof(*temp) * (i + 1));
	if (temp == NULL)
		return (NULL);
	ft_strcpy(temp, s1);
	return (temp);
}
