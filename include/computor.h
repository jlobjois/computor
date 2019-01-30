/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 13:51:59 by jlobjois          #+#    #+#             */
/*   Updated: 2017/09/23 13:52:08 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include "libft.h"
#include <stdio.h>

typedef struct		s_eq
{
	int				deg2;
	int				deg1;
	int				passage;
	int				*deg;
	int				tmpdeg;
	int				signe;
	int				postequal;
	int				i;
	int				j;
	int				equal;
	int				test;
	int				nbx;
	int				decalage;
	int				max0;
	int				max1;
	int				vtff;
	int				total;
	double			tmp;
	double			delta;
	double			sol1;
	double			sol2;
	double			solr;
	double			sol1i;
	double			sol2i;
	double			*x;
}					t_eq;

void				norme5(t_eq *eq);
void				normeparser1 (t_eq *eq, char **side, int j);
void				normeparser2 (t_eq *eq, char **side, int j);
void				normeparser3(t_eq *eq, char **side);
void				normeparser4(t_eq *eq, char **side);
void				normeparser5(t_eq *eq, char **side);
void				normeparser6(t_eq *eq);
void				ft_str_is_numeric2(char *str, t_eq *eq);
void				parserfin(t_eq *eq);
void				parsersuite2(t_eq *eq, char **tab, int j);
void				parsersuite(t_eq *eq, char **tab, int j);
void				parser(t_eq *eq, char **tab, int j);
double				ft_sqrt(double delta);
double				ft_atof(char const *nptr, t_eq *eq);
void				calcul(t_eq *eq);
void				affichagesuite (t_eq *eq);
void				affichage3(t_eq *eq);
void				affichage2(t_eq *eq);
void				affichage(t_eq *eq);
void				ft_error(char *str, t_eq *eq);
void				alwaystrue();
void				alwaysfalse(t_eq *eq);
void				xzero(t_eq *eq);
void				calcul1(t_eq *eq);
void				calcul2(t_eq *eq);
void				affdouble(double data);

#endif
