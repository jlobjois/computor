/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 13:56:43 by jlobjois          #+#    #+#             */
/*   Updated: 2017/09/23 13:56:45 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

double	ft_sqrt(double delta)
{
	double increase;
	double try;

	increase = 1.0;
	try = 0.0;
	if (delta <= 0)
		return (0);
	while (increase >= 0.00000001)
	{
		while (delta > (try * try))
			try += increase;
		if (delta == (try * try))
			return (try);
		try -= increase;
		increase /= 10;
	}
	return (try);
}

void	anditsover(t_eq *eq)
{
	ft_putstr("Discriminant is strictly negative, ");
	ft_putstr("the two solutions are:\n");
	affdouble(eq->solr);
	ft_putstr(" + ");
	affdouble(eq->sol1i);
	ft_putstr("i\n");
	affdouble(eq->solr);
	ft_putstr(" + ");
	affdouble(eq->sol2i);
	ft_putstr("i\n");
}

void	affichagefin(t_eq *eq)
{
	if ((eq->deg[2] == 2 && eq->x[2] != 0)
	|| (eq->deg[1] == 2 && eq->x[1] != 0))
	{
		if (eq->delta > 0)
		{
			ft_putstr("Discriminant is strictly positive, ");
			ft_putstr("the two solutions are:\n");
			affdouble(eq->sol1);
			write(1, "\n", 1);
			affdouble(eq->sol2);
			write(1, "\n", 1);
		}
		if (eq->delta < 0)
			anditsover(eq);
		if (eq->delta == 0)
		{
			ft_putstr("Discriminant equal zero, the solution is:\n");
			affdouble(eq->sol1);
			write(1, "\n", 1);
		}
	}
}

void	affichagesuite(t_eq *eq)
{
	int i;

	i = eq->nbx;
	while (eq->deg[i] == 0 && eq->x[i] == 0)
		i--;
	ft_putstr("Polynomial degree: ");
	ft_putnbr(eq->deg[i]);
	write(1, "\n", 1);
	affichagefin(eq);
}
