/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:43:24 by jlobjois          #+#    #+#             */
/*   Updated: 2017/09/23 18:43:25 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_str_is_numeric2(char *str, t_eq *eq)
{
	int i;
	int test;

	test = 0;
	i = -1;
	if (str[0] == '.')
		ft_error("wrong number", eq);
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] != '.')
				ft_error("wrong number", eq);
			else
				test++;
		}
	}
	if (test > 1)
		ft_error("wrong number", eq);
}

void	parserfin(t_eq *eq)
{
	if (eq->test != 4)
		ft_error("wrong arguments", eq);
	eq->test = 0;
}

void	parsersuite2(t_eq *eq, char **side, int j)
{
	if (eq->i <= (j - 1))
	{
		if (eq->test == 2)
			normeparser4(eq, side);
		if (eq->test == 3)
		{
			normeparser5(eq, side);
			eq->test++;
		}
	}
	else
	{
		eq->x[0] += (eq->tmp * eq->postequal * eq->signe);
		eq->test = 4;
	}
	parserfin(eq);
}

void	parsersuite(t_eq *eq, char **side, int j)
{
	if (eq->test == 0)
	{
		if ((side[eq->i][0] != '+' && side[eq->i][0] != '-')
		|| side[eq->i][1] != '\0')
			ft_error("wrong arguments 2", eq);
		if (side[eq->i][0] == '+')
			eq->signe = 1;
		if (side[eq->i][0] == '-')
			eq->signe = -1;
		eq->test++;
		eq->i++;
		if (eq->i == j || side[eq->i][0] == '\0')
			parserfin(eq);
	}
	if (eq->test == 1)
	{
		eq->tmp = ft_atof(side[eq->i], eq);
		ft_str_is_numeric2(side[eq->i], eq);
		eq->test++;
		eq->i++;
	}
	parsersuite2(eq, side, j);
}

void	parser(t_eq *eq, char **side, int j)
{
	eq->signe = 1;
	if (j < 3)
	{
		normeparser1(eq, side, j);
		normeparser2(eq, side, j);
	}
	else
	{
		while (side[eq->i] && side[eq->i + 1] != '\0')
		{
			if (eq->i == 0 && eq->passage < 1)
			{
				if (((eq->tmp = ft_atof(side[eq->i], eq)) == 0.000000))
				{
					normeparser3(eq, side);
					eq->test++;
				}
				else
					eq->test += 2;
				eq->passage++;
			}
			eq->i++;
			parsersuite(eq, side, j);
		}
	}
}
