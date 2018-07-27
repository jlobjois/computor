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

void	affichagefin(t_eq *eq)
{
	if ((eq->deg[2] == 2 && eq->x[2] != 0) || (eq->deg[1] == 2 && eq->x[1] != 0))
	{
		if (eq->delta > 0)
		{
			printf("Discriminant is strictly positive, ");
			printf("the two solutions are:\n");
			affdouble(eq->sol1);
			printf("\n");
			affdouble(eq->sol2);
			printf("\n");
		}
		if (eq->delta < 0)
		{
			printf("Discriminant is strictly negative, ");
			printf("the two solutions are:\n");
			printf("%f + %fi\n%f", eq->solr, eq->sol1i, eq->solr);
			printf(" + %fi\n", eq->sol2i);
		}
		if (eq->delta == 0)
		{
			printf("Discriminant equal zero, the solution is:\n");
			affdouble(eq->sol1);
			printf("\n");
		}
	}
}

void	affichagesuite(t_eq *eq)
{
	int i;

	i = eq->nbx;
	while (eq->deg[i] == 0 && eq->x[i] == 0)
		i--;
	printf("Polynomial degree: %d\n", eq->deg[i]);
	affichagefin(eq);
}
