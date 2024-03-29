/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:53:23 by jlobjois          #+#    #+#             */
/*   Updated: 2022/11/01 17:13:41 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	alwaystrue(t_eq *eq)
{
	ft_putstr("Reduced form: 0 = 0\n");
	writepolynomial(eq);
	ft_error("Always true", eq);
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
	writepolynomial(eq);
	ft_error("Always false", eq);
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
	writepolynomial(eq);
	ft_error("The solution is:\nX = 0", eq);
}

void	onesolution(t_eq *eq)
{
	ft_putstr("Reduced form: ");
	eq->i = 0;
	while (eq->i <= eq->nbx)
	{
		if (eq->x[eq->i] != 0)
			writeone(eq);
		eq->i++;
	}
	ft_putstr("= 0\n");
	writepolynomial(eq);
	eq->solr = -eq->x[0] / eq->x[1];
	ft_putstr("The solution is:\n");
	affdouble(eq->solr);
	write(1, "\n", 1);
}

void	seconddegree(t_eq *eq)
{
	while (eq->deg[eq->deg2] != 2 && eq->deg2 < 3)
		eq->deg2++;
	while (eq->deg[eq->deg1] != 1 && eq->deg1 < 2)
		eq->deg1++;
	eq->delta = (eq->x[eq->deg1] * eq->x[eq->deg1])
		- (4 * eq->x[eq->deg2] * eq->x[0]);
	if (eq->delta > 0)
	{
		eq->sol1 = (((-eq->x[eq->deg1])
					+ ft_sqrt(eq->delta)) / (2 * eq->x[eq->deg2]));
		eq->sol2 = (((-eq->x[eq->deg1])
					- ft_sqrt(eq->delta)) / (2 * eq->x[eq->deg2]));
	}
	if (eq->delta == 0)
		eq->sol1 = (-eq->x[eq->deg1]) / (2 * eq->x[eq->deg2]);
	if (eq->delta < 0)
	{
		eq->solr = (-eq->x[eq->deg1]) / (2 * eq->x[eq->deg2]);
		eq->sol1i = (ft_sqrt(-eq->delta)) / (2 * eq->x[eq->deg2]);
		eq->sol2i = (ft_sqrt(-eq->delta)) / (2 * eq->x[eq->deg2]);
	}
	reducedform(eq);
}
