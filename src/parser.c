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

void	ft_str_is_numeric2(char *str)
{
	int i;
	int test;

	test = 0;
	i = -1;
	if (str[0] == '.')
		ft_error("wrong number");
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] != '.')
				ft_error("wrong number");
			else
				test++;
		}
	}
	if (test > 1)
		ft_error("wrong number");
}

void	parserfin(t_eq *eq)
{
	if (eq->test != 4)
		ft_error("wrong arguments");
	eq->test = 0;
}

void	parsersuite2(t_eq *eq, char **troll, int j)
{
	if (eq->i <= (j - 1))
	{
		if (eq->test == 2)
			normeparser4(eq, troll);
		if (eq->test == 3)
		{
			normeparser5(eq, troll);
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

void	parsersuite(t_eq *eq, char **troll, int j)
{
	if (eq->test == 0)
	{
		if ((troll[eq->i][0] != '+' && troll[eq->i][0] != '-')
		|| troll[eq->i][1] != '\0')
			ft_error("wrong arguments 2");
		if (troll[eq->i][0] == '+')
			eq->signe = 1;
		if (troll[eq->i][0] == '-')
			eq->signe = -1;
		eq->test++;
		eq->i++;
		if (troll[eq->i][0] == '\0')
			parserfin(eq);
	}
	if (eq->test == 1)
	{
		if ((eq->tmp = ft_atof(troll[eq->i])) == 0.0)
			ft_error("wrong arguments 3");
		ft_str_is_numeric2(troll[eq->i]);
		eq->test++;
		eq->i++;
	}
	parsersuite2(eq, troll, j);
}

void	parser(t_eq *eq, char **troll, int j)
{
	eq->signe = 1;
	if (j < 3)
	{
		normeparser1(eq, troll, j);
		normeparser2(eq, troll, j);
	}
	else
	{
		while (troll[eq->i] && troll[eq->i + 1] != '\0')
		{
			if (eq->i == 0 && eq->passage < 1)
			{
				if (((eq->tmp = ft_atof(troll[eq->i])) == 0.000000))
				{
					normeparser3(eq, troll);
					eq->test++;
				}
				else
					eq->test += 2;
				eq->passage++;
			}
			eq->i++;
			parsersuite(eq, troll, j);
		}
	}
}
