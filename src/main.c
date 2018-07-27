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

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	norme(t_eq *eq, char **troll0)
{
	while (troll0[eq->max0])
	{
		if (troll0[eq->max0][0] == 'X')
		{
			if (troll0[eq->max0][1] != '^')
				ft_error("wrong arguments");
			eq->nbx++;
		}
		eq->max0++;
	}
}

void	norme1(t_eq *eq, char **troll1)
{
	while (troll1[eq->max1])
	{
		if (troll1[eq->max1][0] == 'X')
		{
			if (troll1[eq->max1][1] != '^')
				ft_error("wrong arguments");
			eq->nbx++;
		}
		eq->max1++;
	}
}

void	norme2(t_eq *eq, char **troll0, char **troll1)
{
	ft_bzero(eq->x, sizeof(double) * (eq->nbx + 1));
	ft_bzero(eq->deg, sizeof(int) * (eq->nbx + 1));
	eq->postequal = 1;
	parser(eq, troll0, eq->max0);
	eq->postequal = -1;
	eq->i = 0;
	eq->passage = 0;
	parser(eq, troll1, eq->max1);
	eq->j = 0;
	calcul(eq);
}

int		main(int argc, char **argv)
{
	t_eq eq;
	char **troll;
	char **troll0;
	char **troll1;

	ft_bzero(&eq, sizeof(eq));
	if (argc != 2)
		ft_error("wrong parameters");
	if (!(troll = ft_strsplit(argv[1], '=')))
		ft_error("error while strsplit");
	if (!troll[0] || !troll[1])
		ft_error("troll[0] and troll[1] do not exist");
	if (troll[2] != NULL)
		ft_error("less equals pls bro");
	troll0 = ft_strsplit(troll[0], ' ');
	troll1 = ft_strsplit(troll[1], ' ');
	norme(&eq, troll0);
	norme1(&eq, troll1);
	if (!(eq.x = malloc((sizeof(double)) * (eq.nbx + 1))))
		ft_error("malloc error");
	if (!(eq.deg = malloc((sizeof(int)) * (eq.nbx + 1))))
		ft_error("malloc error");
	norme2(&eq, troll0, troll1);
	return (0);
}
