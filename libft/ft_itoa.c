/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 23:48:29 by jlobjois          #+#    #+#             */
/*   Updated: 2022/11/01 19:30:46 by vgeorgak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_len(int n)
{
	size_t		i;

	i = 1;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			i;
	unsigned int	tmp;

	i = ft_int_len(n);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		i++;
	}
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	str[--i] = tmp % 10 + '0';
	while (tmp)
	{
		str[--i] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
