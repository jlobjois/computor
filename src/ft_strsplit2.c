/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlobjois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 23:48:45 by jlobjois          #+#    #+#             */
/*   Updated: 2022/11/01 17:17:44 by jlobjois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static char	let_n_char(char const *s, char c, size_t id_w, size_t id_c)
{
	size_t		n_words;
	size_t		n_chars;

	n_words = 0;
	n_chars = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			n_words++;
		while (*s != c && *s)
		{
			if (id_w == n_words)
			{
				n_chars++;
				if (n_chars == id_c)
					return (*s);
			}
			s++;
		}
	}
	return (0);
}

static size_t	get_n_chars(char const *s, char c, size_t id_word)
{
	size_t		n_words;
	size_t		n_chars;

	n_words = 0;
	n_chars = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			n_words++;
		while (*s != c && *s)
		{
			if (id_word == n_words)
				n_chars++;
			s++;
		}
	}
	return (n_chars);
}

static size_t	get_n_words(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n);
}

char	**ft_strsplit2(char const *s, char c, t_eq *eq, size_t i)
{
	char		**ptr;
	size_t		j;

	if (!s)
		ft_error("Error in split", eq);
	ptr = (char **)malloc(sizeof(*ptr) * (get_n_words(s, c) + 1));
	if (!ptr)
		ft_error("Error in split", eq);
	while (i < get_n_words(s, c))
	{
		ptr[i] = (char *)malloc(sizeof(char) * (get_n_chars(s, c, i + 1) + 1));
		if (!ptr[i])
			ft_error("Error in split", eq);
		j = 0;
		while (j < get_n_chars(s, c, i + 1))
		{
			ptr[i][j] = let_n_char(s, c, i + 1, j + 1);
			j++;
		}
		ptr[i][j] = '\0';
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
