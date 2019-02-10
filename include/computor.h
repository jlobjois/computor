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
	double			tmp;
	double			delta;
	double			sol1;
	double			sol2;
	double			solr;
	double			sol1i;
	double			sol2i;
	double			*x;
}					t_eq;

void				writeone(t_eq *eq);
void				firstcheck (t_eq *eq, char **side, int j);
void				secondcheck (t_eq *eq, char **side, int j);
void				thirdcheck(t_eq *eq, char **side);
void				fourthcheck(t_eq *eq, char **side);
void				fifthcheck(t_eq *eq, char **side);
void				insertpowervalue(t_eq *eq);
void				ft_str_is_numeric2(char *str, t_eq *eq);
void				parserfin(t_eq *eq);
void				parsersuite2(t_eq *eq, char **tab, int j);
void				parsersuite(t_eq *eq, char **tab, int j);
void				parser(t_eq *eq, char **tab, int j);
double				ft_sqrt(double delta);
double				ft_atof(char const *nptr, t_eq *eq);
void				differentcases(t_eq *eq);
void				writepolynomial(t_eq *eq);
void				morethantwo(t_eq *eq);
void				reducedform(t_eq *eq);
void				ft_error(char *str, t_eq *eq);
void				alwaystrue(t_eq *eq);
void				alwaysfalse(t_eq *eq);
void				xzero(t_eq *eq);
void				onesolution(t_eq *eq);
void				seconddegree(t_eq *eq);
void				affdouble(double data);
char				**ft_strsplit2(char const *s, char c, t_eq *eq);

#endif
