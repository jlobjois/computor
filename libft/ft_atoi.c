/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 09:35:26 by jlobjois          #+#    #+#             */
/*   Updated: 2022/11/01 18:50:18 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_calcul(int i, int neg, char *str)
{
	long	tmp;
	long	n;

	tmp = 0;
	n = 0;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = 10 * n + (str[i] - '0');
		n = tmp;
		i++;
	}
	tmp *= neg;
	return (tmp);
}

long	ft_atoi(char const *nptr)
{
	int	i;
	int	neg;

	neg = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\f' || nptr[i] == '\v' || nptr[i] == '\r')
		i++;
	if (nptr[i] < '0' && nptr[i] > '9' && nptr[i] != '-' && nptr[i] != '+')
		return (0);
	else if (nptr[i] == '-')
	{
		neg = -1;
		i++;
		return (ft_calcul(i, neg, (char *)nptr));
	}
	else if (nptr[i] == '+')
		return (ft_calcul(++i, neg, (char *)nptr));
	return (ft_calcul(i, neg, (char *)nptr));
}
