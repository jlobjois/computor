/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:11:13 by jlobjois          #+#    #+#             */
/*   Updated: 2017/07/17 21:31:25 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

double			suite(int i, char *str, double tmp)
{
	double k;

	k = 10;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp += (((str[i] - '0')) / k);
		k *= 10;
		i++;
	}
	if (str[i])
		if (str[i] == '.')
			ft_error("not a good double");
	return (tmp);
}

static double	ft_calcul(int i, int neg, char *str)
{
	double	tmp;
	int		n;

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
	if (str[i] == '.')
	{
		i++;
		tmp = suite(i, str, tmp);
	}
	tmp *= neg;
	return (tmp);
}

double			ft_atof(char const *nptr)
{
	int i;
	int neg;

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

void			normeparser6(t_eq *eq)
{
	eq->decalage = 0;
	while (((eq->j + eq->decalage) < eq->nbx)
	&& (eq->deg[eq->j + eq->decalage] != 0))
		eq->decalage++;
	while (eq->decalage > 0)
	{
		eq->x[eq->j + eq->decalage] = eq->x[eq->j + eq->decalage - 1];
		eq->deg[eq->j + eq->decalage] = eq->deg[eq->j + eq->decalage - 1];
		eq->deg[eq->j + eq->decalage - 1] = 0;
		eq->x[eq->j + eq->decalage - 1] = 0;
		eq->decalage--;
	}
	eq->deg[eq->j] = eq->tmpdeg;
	eq->x[eq->j] += (eq->tmp * eq->postequal * eq->signe);
}
