/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:53:23 by jlobjois          #+#    #+#             */
/*   Updated: 2017/09/27 19:53:26 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	alwaystrue(void)
{
	ft_putstr("Reduced form: 0 = 0\n");
	ft_error("Always true");
}

void	alwaysfalse(t_eq *eq)
{
	ft_putstr("Reduced form: ");
	if (eq->x[0] != 0)
	{
		ft_putnbr(eq->x[0]);
		write(1, " * X^0 ", 7);
	}
	ft_putstr("= 0\n");
	ft_error("Always false");
}

void	xzero(t_eq *eq)
{
	ft_putstr("Reduced form: ");
	while (eq->j != 0)
	{
		if (eq->x[eq->j] != 0)
		{
			ft_putnbr(eq->x[eq->j]);
			write(1, " * X^", 5);
			ft_putnbr(eq->deg[eq->j]);
			write(1, " ", 1);
		}
		eq->j--;
	}
	ft_putstr("= 0\n");
	ft_error("The solution is:\nX = 0");
}

void	calcul1(t_eq *eq)
{
	ft_putstr("Reduced form: ");
	while (eq->j != 0)
	{
		if (eq->x[eq->j] != 0)
		{
			if (eq->x[1] != 0)
			{
				ft_putnbr(eq->x[1]);
				write(1, " * X^1 ", 7);
			}
			if (eq->x[0] != 0)
			{
				ft_putnbr(eq->x[0]);
				write(1, " * X^0 ", 7);
			}
		}
		eq->j--;
	}
	ft_putstr("= 0\n");
	eq->solr = (-eq->x[0]) / eq->x[1];
	ft_putstr("The solution is:\n");
	affdouble(eq->solr);
	write(1, "\n", 1);
}

void	calcul2(t_eq *eq)
{
	while (eq->deg[eq->deg2] != 2 && eq->deg2 < 3)
		eq->deg2++;
	while (eq->deg[eq->deg1] != 1 && eq->deg1 < 2)
		eq->deg1++;
	eq->delta = (eq->x[eq->deg1] * eq->x[eq->deg1]) -
	(4 * eq->x[eq->deg2] * eq->x[0]);
	if (eq->delta > 0)
	{
		eq->sol1 = (((-eq->x[eq->deg1]) +
		ft_sqrt(eq->delta)) / (2 * eq->x[eq->deg2]));
		eq->sol2 = (((-eq->x[eq->deg1]) -
		ft_sqrt(eq->delta)) / (2 * eq->x[eq->deg2]));
	}
	if (eq->delta == 0)
		eq->sol1 = (-eq->x[eq->deg1]) / (2 * eq->x[eq->deg2]);
	if (eq->delta < 0)
	{
		eq->solr = (-eq->x[eq->deg1]) / (2 * eq->x[eq->deg2]);
		eq->sol1i = (ft_sqrt(-eq->delta)) / (2 * eq->x[eq->deg2]);
		eq->sol2i = (ft_sqrt(-eq->delta)) / (2 * eq->x[eq->deg2]);
	}
	affichage2(eq);
}
