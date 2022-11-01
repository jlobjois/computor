/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 13:55:00 by jlobjois          #+#    #+#             */
/*   Updated: 2022/11/01 17:18:21 by jlobjois         ###   ########.fr       */
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

int	get_max(t_eq *eq, char **side)
{
	int	max;

	max = 0;
	while (side[max])
	{
		if (side[max][0] == 'X')
		{
			if (side[max][1] != '^')
				ft_error("wrong argument after X", eq);
			eq->nbx++;
		}
		max++;
	}
	return (max);
}

static void	continue_init(t_eq *eq)
{
	if (eq->max0 < 1 || eq->max1 < 1)
		ft_error("size problem", eq);
	if (eq->nbx < 2)
		eq->x = malloc((sizeof(double)) * (3));
	else
		eq->x = malloc((sizeof(double)) * (eq->nbx + 1));
	if (!eq->x)
		ft_error("malloc error", eq);
	if (eq->nbx < 2)
		eq->deg = malloc((sizeof(int)) * (3));
	else
		eq->deg = malloc((sizeof(int)) * (eq->nbx + 1));
	if (!eq->deg)
		ft_error("malloc error", eq);
	if (eq->nbx < 2)
	{
		ft_bzero(eq->x, sizeof(double) * (3));
		ft_bzero(eq->deg, sizeof(int) * (3));
	}
	else
	{
		ft_bzero(eq->x, sizeof(double) * (eq->nbx + 1));
		ft_bzero(eq->deg, sizeof(int) * (eq->nbx + 1));
	}
}

void	init(t_eq *eq, char **side0, char **side1)
{
	continue_init(eq);
	eq->postequal = 1;
	parser(eq, side0, eq->max0);
	eq->postequal = -1;
	eq->i = 0;
	eq->passage = 0;
	parser(eq, side1, eq->max1);
	eq->j = 0;
	differentcases(eq);
	free(eq->side[1]);
	free(eq->side[0]);
	free(eq->side);
}

int	main(int argc, char **argv)
{
	t_eq	eq;

	ft_bzero(&eq, sizeof(eq));
	if (argc != 2)
		ft_error("wrong parameters", &eq);
	eq.side = ft_strsplit(argv[1], '=');
	if (!eq.side)
		ft_error("error while strsplit", &eq);
	if (!eq.side[0] || !eq.side[1])
		ft_error("side[0] and side[1] do not exist", &eq);
	if (eq.side[2] != NULL)
		ft_error("less equals pls", &eq);
	eq.side0 = ft_strsplit2(eq.side[0], ' ', &eq, 0);
	eq.side1 = ft_strsplit2(eq.side[1], ' ', &eq, 0);
	eq.max0 = get_max(&eq, eq.side0);
	eq.max1 = get_max(&eq, eq.side1);
	init(&eq, eq.side0, eq.side1);
	if (eq.x != NULL)
		free(eq.x);
	if (eq.deg != NULL)
		free(eq.deg);
	return (0);
}
