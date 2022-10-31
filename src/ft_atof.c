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

double			suite(int i, char *str, double tmp, t_eq *eq)
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
			ft_error("not a good double", eq);
	return (tmp);
}

static double	ft_calcul(int i, int neg, char *str, t_eq *eq)
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
		tmp = suite(i, str, tmp, eq);
	}
	else if (str[i] != '\0')
		ft_error("not a good double", eq);
	tmp *= neg;
	return (tmp);
}

double			ft_atof(char const *nptr, t_eq *eq)
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
		return (ft_calcul(i, neg, (char *)nptr, eq));
	}
	else if (nptr[i] == '+')
		return (ft_calcul(++i, neg, (char *)nptr, eq));
	return (ft_calcul(i, neg, (char *)nptr, eq));
}

void			insertpowervalue(t_eq *eq)
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
