/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 13:55:00 by jlobjois          #+#    #+#             */
/*   Updated: 2017/09/23 13:55:02 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_error(char *str, t_eq *eq)
{
	if (eq->x != NULL)
		free(eq->x);
	if (eq->deg != NULL)
		free(eq->deg);
	ft_putendl(str);
	exit(0);
}

void	norme(t_eq *eq, char **side0)
{
	while (side0[eq->max0])
	{
		if (side0[eq->max0][0] == 'X')
		{
			if (side0[eq->max0][1] != '^')
				ft_error("wrong argument after X", eq);
			eq->nbx++;
		}
		eq->max0++;
	}
}

void	norme1(t_eq *eq, char **side1)
{
	while (side1[eq->max1])
	{
		if (side1[eq->max1][0] == 'X')
		{
			if (side1[eq->max1][1] != '^')
				ft_error("wrong argument after X", eq);
			eq->nbx++;
		}
		eq->max1++;
	}
}

void	norme2(t_eq *eq, char **side0, char **side1)
{
	ft_bzero(eq->x, sizeof(double) * (eq->nbx + 1));
	ft_bzero(eq->deg, sizeof(int) * (eq->nbx + 1));
	eq->postequal = 1;
	parser(eq, side0, eq->max0);
	eq->postequal = -1;
	eq->i = 0;
	eq->passage = 0;
	parser(eq, side1, eq->max1);
	eq->j = 0;
	calcul(eq);
}

int		main(int argc, char **argv)
{
	t_eq eq;
	char **side;
	char **side0;
	char **side1;

	(void)argc;
	ft_bzero(&eq, sizeof(eq));
	if (argc != 2)
		ft_error("wrong parameters", &eq);
	if (!(side = ft_strsplit(argv[1], '=')))
		ft_error("error while strsplit", &eq);
	if (!side[0] || !side[1])
		ft_error("side[0] and side[1] do not exist", &eq);
	if (side[2] != NULL)
		ft_error("less equals pls", &eq);
	side0 = ft_strsplit(side[0], ' ');
	side1 = ft_strsplit(side[1], ' ');
	norme(&eq, side0);
	norme1(&eq, side1);
	if (!(eq.x = malloc((sizeof(double)) * (eq.nbx + 1))))
		ft_error("malloc error", &eq);
	if (!(eq.deg = malloc((sizeof(int)) * (eq.nbx + 1))))
		ft_error("malloc error", &eq);
	norme2(&eq, side0, side1);
	return (0);
}
