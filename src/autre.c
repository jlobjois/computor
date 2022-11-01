/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 18:58:01 by jlobjois          #+#    #+#             */
/*   Updated: 2017/09/29 18:58:03 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	writepowerovertwo(t_eq *eq)
{
	int		i;

	i = eq->nbx;
	while (eq->deg[i] == 0 && eq->x[i] == 0)
		i--;
	ft_putstr("Polynomial degree: ");
	affdouble(eq->deg[i]);
	write(1, "\n", 1);
	ft_putstr("The polynomial degree");
	ft_error(" is stricly greater than 2, I can't solve.", eq);
}

void	writepower(t_eq *eq)
{
	if (eq->i != 0)
	{
		write(1, "+ ", 2);
	}
	affdouble(eq->x[eq->i]);
	write(1, " * X^", 5);
	affdouble(eq->deg[eq->i]);
	write(1, " ", 1);
}

void	morethantwo(t_eq *eq)
{
	ft_putstr("Reduced form: ");
	eq->i = 0;
	while (eq->i <= eq->nbx)
	{
		if (eq->x[eq->i] != 0)
		{
			if (eq->x[eq->i] < 0)
			{
				eq->x[eq->i] *= -1;
				write(1, "- ", 2);
				affdouble(eq->x[eq->i]);
				write(1, " * X^", 5);
				affdouble(eq->deg[eq->i]);
				write(1, " ", 1);
			}
			else
				writepower(eq);
		}
		eq->i++;
	}
	ft_putstr("= 0\n");
	writepowerovertwo(eq);
}

static void	suiteaff(long valeur)
{
	if (valeur < 9)
		ft_putstr("00000");
	else if (valeur < 99)
		ft_putstr("0000");
	else if (valeur < 999)
		ft_putstr("000");
	ft_putnbr(valeur);
}

void	affdouble(double data)
{
	long		valeur;

	valeur = (long)((data - ((double)(long)data)) * 1000000);
	if (data < 0)
	{
		ft_putchar('-');
		data *= -1;
		valeur *= -1;
	}
	ft_putnbr((long)data);
	if (valeur != 0)
	{
		ft_putchar('.');
		if (valeur < 999)
			suiteaff(valeur);
		else if (valeur < 9999)
			ft_putstr("00");
		else if (valeur < 99999)
			ft_putstr("0");
		if (valeur >= 999)
			ft_putnbr(valeur);
	}
}
