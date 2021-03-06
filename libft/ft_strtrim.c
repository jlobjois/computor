/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:26:25 by jlobjois          #+#    #+#             */
/*   Updated: 2016/11/19 22:26:26 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*tri;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
	{
		end--;
		if (end == 0)
			return (ft_strdup(""));
	}
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	tri = ft_strsub(s, start, (1 + end - start));
	return (tri);
}
