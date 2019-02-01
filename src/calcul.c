/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:51:17 by jlobjois          #+#    #+#             */
/*   Updated: 2017/07/17 21:51:54 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	norme5(t_eq *eq)
{
	if (eq->x[eq->i] < 0)
	{
		eq->x[eq->i] *= -1;
		write(1, "- ", 2);
		affdouble(eq->x[eq->i]);
		write(1, " * X^", 5);
		ft_putnbr((int)eq->deg[eq->i]);
		write(1, " ", 1);
	}
	else
	{
		if (eq->i != 0)
			write(1, "+ ", 2);
		affdouble(eq->x[eq->i]);
		write(1, " * X^", 5);
		ft_putnbr((int)eq->deg[eq->i]);
		write(1, " ", 1);
	}
}

void	affichage2(t_eq *eq)
{
	ft_putstr("Reduced form: ");
	eq->i = 0;
	while (eq->i <= eq->nbx)
	{
		if (eq->x[eq->i] != 0)
			norme5(eq);
		eq->i++;
	}
	ft_putstr("= 0\n");
	ft_putstr("delta = ");
	affdouble(eq->delta);
	write(1, "\n", 1);
	affichagesuite(eq);
}

void	norme7(t_eq *eq)
{
	if ((eq->j == 1 && (eq->deg[eq->j] == 1 && eq->x[eq->j] != 0))
		&& (eq->x[eq->j - 1] != 0))
		calcul1(eq);
	else if ((eq->j == 1 && (eq->deg[eq->j] == 1 && eq->x[eq->j] != 0))
		&& (eq->x[eq->j - 1] == 0))
		xzero(eq);
	else if ((eq->j == 2 && (eq->deg[eq->j] == 2 && eq->x[eq->j] == 0))
		&& (eq->x[eq->j - 1] == 0 && eq->x[eq->j - 2] == 0))
		alwaystrue(eq);
	else if ((eq->j == 2 && (eq->deg[eq->j] == 2 && eq->x[eq->j] == 0))
		&& (eq->x[eq->j - 1] != 0 && eq->x[eq->j - 2] != 0))
		calcul1(eq);
	else if ((eq->j == 2 && (eq->deg[eq->j] == 2 && eq->x[eq->j] == 0))
		&& (eq->x[eq->j - 1] != 0 || eq->x[eq->j - 2] != 0))
		alwaysfalse(eq);
	else if ((eq->j == 2 && (eq->deg[eq->j] == 2 && eq->x[eq->j] != 0))
		&& (eq->x[eq->j - 1] == 0 && eq->x[eq->j - 2] == 0))
		xzero(eq);
	else if ((eq->j == 2 && (eq->deg[eq->j] == 2 && eq->x[eq->j] != 0))
		&& (eq->x[eq->j - 1] != 0 || eq->x[eq->j - 2] != 0))
		calcul2(eq);
	else
		affichage3(eq);
}

void	norme6(t_eq *eq)
{
	if (eq->j == 0 && eq->x[eq->j] == 0)
		alwaystrue(eq);
	else if (eq->j == 0 && eq->x[eq->j] != 0)
		alwaysfalse(eq);
	else if ((eq->j == 1 && (eq->deg[eq->j] == 2 && eq->x[eq->j] == 0))
		&& (eq->x[eq->j - 1] == 0))
		alwaystrue(eq);
	else if ((eq->j == 1 && (eq->deg[eq->j] == 2 && eq->x[eq->j] == 0))
		&& (eq->x[eq->j - 1] != 0))
		alwaysfalse(eq);
	else if ((eq->j == 1 && (eq->deg[eq->j] == 2 && eq->x[eq->j] != 0))
		&& (eq->x[eq->j - 1] == 0))
		xzero(eq);
	else if ((eq->j == 1 && (eq->deg[eq->j] == 2 && eq->x[eq->j] != 0))
		&& (eq->x[eq->j - 1] != 0))
		calcul2(eq);
	else if ((eq->j == 1 && (eq->deg[eq->j] == 1 && eq->x[eq->j] == 0))
		&& (eq->x[eq->j - 1] != 0))
		alwaysfalse(eq);
	else if ((eq->j == 1 && (eq->deg[eq->j] == 1 && eq->x[eq->j] == 0))
		&& (eq->x[eq->j - 1] == 0))
		alwaystrue(eq);
	else
		norme7(eq);
}

void	calcul(t_eq *eq)
{
	eq->j = eq->nbx;
	eq->test = 0;
	while (eq->deg[eq->j] == 0 && eq->x[eq->j] == 0)
		eq->j--;
	while (eq->deg[eq->j] > 2 && eq->x[eq->j] == 0)
		eq->j--;
	if (eq->j == -1)
		alwaystrue(eq);
	if (eq->j > 2)
		affichage3(eq);
	eq->j = eq->nbx;
	while (eq->deg[eq->j] == 0 && eq->x[eq->j] == 0)
		eq->j--;
	if ((eq->j == 0 && (eq->deg[eq->j] == 2 && eq->x[eq->j] == 0)))
		alwaystrue(eq);
	else if ((eq->j == 0 && (eq->deg[eq->j] == 2 && eq->x[eq->j] != 0)))
		xzero(eq);
	else if ((eq->j == 0 && (eq->deg[eq->j] == 1 && eq->x[eq->j] == 0)))
		alwaystrue(eq);
	else if ((eq->j == 0 && (eq->deg[eq->j] == 1 && eq->x[eq->j] != 0)))
		xzero(eq);
	else
		norme6(eq);
}
