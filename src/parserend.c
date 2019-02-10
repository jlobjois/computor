/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 13:56:43 by jlobjois          #+#    #+#             */
/*   Updated: 2017/09/23 13:56:45 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	firstcheck(t_eq *eq, char **side, int j)
{
	if (j == 1)
	{
		if (((eq->tmp = ft_atof(side[eq->i], eq)) == 0.000000))
		{
			if (side[eq->i][0] != '0' || side[eq->i][1] != '\0')
				ft_error("wrong argument atof", eq);
		}
		else
		{
			ft_str_is_numeric2(side[eq->i], eq);
			eq->x[0] += (eq->tmp * eq->postequal * eq->signe);
		}
	}
}

void	secondcheck(t_eq *eq, char **side, int j)
{
	if (j == 2)
	{
		if ((side[0][0] != '+' && side[0][0] != '-') || side[0][1] != '\0')
			ft_error("wrong arguments", eq);
		if (side[0][0] == '+')
			eq->signe = 1;
		if (side[0][0] == '-')
			eq->signe = -1;
		if (((eq->tmp = ft_atof(side[1], eq)) == 0.000000))
		{
			if (side[1][0] != '0' || side[1][1] != '\0')
				ft_error("wrong argument atof", eq);
		}
		else
		{
			ft_str_is_numeric2(side[1], eq);
			eq->x[0] += (eq->tmp * eq->postequal * eq->signe);
		}
	}
}

void	thirdcheck(t_eq *eq, char **side)
{
	if ((side[eq->i][0] != '+' && side[eq->i][0] != '-')
		|| side[eq->i][1] != '\0')
		ft_error("wrong arguments 1", eq);
	if (side[eq->i][0] == '+')
		eq->signe = 1;
	if (side[eq->i][0] == '-')
		eq->signe = -1;
	if (side[eq->i][0] == '0')
		eq->test++;
}

void	fourthcheck(t_eq *eq, char **side)
{
	if (side[eq->i][0] == '-' || side[eq->i][0] == '+')
	{
		eq->x[0] += (eq->tmp * eq->postequal * eq->signe);
		eq->test = 4;
		eq->i--;
	}
	else
	{
		if (side[eq->i][0] == '\0')
			ft_error("wrong arguments 4", eq);
		if (side[eq->i][0] != '*' || side[eq->i][1] != '\0')
			ft_error("wrong arguments 5", eq);
		eq->test++;
		eq->i++;
	}
}

void	fifthcheck(t_eq *eq, char **side)
{
	if (side[eq->i][0] != 'X' && side[eq->i][1] != '^')
		ft_error("wrong arguments 6", eq);
	if (((eq->tmpdeg = ft_atoi(&side[eq->i][2])) == 0)
		&& side[eq->i][2] != '0')
		ft_error("wrong arguments 7", eq);
	if (eq->tmpdeg < 0)
		ft_error("wrong arguments 8", eq);
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
		insertpowervalue(eq);
}
