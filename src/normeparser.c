/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normeparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 13:56:43 by jlobjois          #+#    #+#             */
/*   Updated: 2017/09/23 13:56:45 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	normeparser1(t_eq *eq, char **troll, int j)
{
	if (j == 1)
	{
		if (((eq->tmp = ft_atof(troll[eq->i])) == 0.000000))
		{
			if (troll[eq->i][0] != '0' || troll[eq->i][1] != '\0')
				ft_error("wrong arguments");
		}
		else
		{
			ft_str_is_numeric2(troll[eq->i]);
			eq->x[0] += (eq->tmp * eq->postequal * eq->signe);
		}
	}
}

void	normeparser2(t_eq *eq, char **troll, int j)
{
	if (j == 2)
	{
		if ((troll[0][0] != '+' && troll[0][0] != '-') || troll[0][1] != '\0')
			ft_error("wrong arguments");
		if (troll[0][0] == '+')
			eq->signe = 1;
		if (troll[0][0] == '-')
			eq->signe = -1;
		if (((eq->tmp = ft_atof(troll[1])) == 0.000000))
		{
			if (troll[1][0] != '0' || troll[1][1] != '\0')
				ft_error("wrong arguments");
		}
		else
		{
			ft_str_is_numeric2(troll[1]);
			eq->x[0] += (eq->tmp * eq->postequal * eq->signe);
		}
	}
}

void	normeparser3(t_eq *eq, char **troll)
{
	if ((troll[eq->i][0] != '+' && troll[eq->i][0] != '-')
	|| troll[eq->i][1] != '\0')
		ft_error("wrong arguments 1");
	if (troll[eq->i][0] == '+')
		eq->signe = 1;
	if (troll[eq->i][0] == '-')
		eq->signe = -1;
	if (troll[eq->i][0] == '0')
		eq->test++;
}

void	normeparser4(t_eq *eq, char **troll)
{
	if (troll[eq->i][0] == '-' || troll[eq->i][0] == '+')
	{
		eq->x[0] += (eq->tmp * eq->postequal * eq->signe);
		eq->test = 4;
		eq->i--;
	}
	else
	{
		if (troll[eq->i][0] == '\0')
			ft_error("wrong arguments 4");
		if (troll[eq->i][0] != '*' || troll[eq->i][1] != '\0')
			ft_error("wrong arguments 5");
		eq->test++;
		eq->i++;
	}
}

void	normeparser5(t_eq *eq, char **troll)
{
	if (troll[eq->i][0] != 'X' && troll[eq->i][1] != '^')
		ft_error("wrong arguments 6");
	if (((eq->tmpdeg = ft_atoi(&troll[eq->i][2])) == 0) &&
	troll[eq->i][2] != '0')
		ft_error("wrong arguments 7");
	if (eq->tmpdeg < 0)
		ft_error("wrong arguments 8");
	eq->j = eq->nbx;
	if (eq->tmpdeg == 0)
		eq->j = 0;
	else
	{
		while (eq->j > 1 && ((eq->tmpdeg < eq->j)
		|| eq->tmpdeg <= eq->deg[eq->j - 1]
		|| (eq->deg[eq->j - 1] == 0 && eq->deg[eq->j] == 0)))
			eq->j--;
	}
	if (eq->tmpdeg == eq->deg[eq->j])
		eq->x[eq->j] += (eq->tmp * eq->postequal * eq->signe);
	else
		normeparser6(eq);
}
