/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 14:19:56 by jlobjois          #+#    #+#             */
/*   Updated: 2016/11/15 18:21:43 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*s;
	size_t		n;
	size_t		len;

	dest = dst;
	s = src;
	n = size;
	while (n-- != 0 && *dest != '\0')
		dest++;
	len = dest - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*dest++ = *s;
			n--;
		}
		s++;
	}
	*dest = '\0';
	return (len + (s - src));
}
