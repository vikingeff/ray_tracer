/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberteau <cberteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 08:49:39 by cberteau          #+#    #+#             */
/*   Updated: 2014/01/13 14:32:34 by cberteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_part(const char **s)
{
	int		count;
	int		len;

	count = 0;
	len = 0;
	while (s[count])
	{
		while(ft_strcmp(s[count], ";") == 0 && s[count])
			count++;
		if (s[count] != NULL)
			len++;
		while (ft_strcmp(s[count], ";") != 0 && s[count])
			count++;
	}
	return (len);
}

char		***ft_strsplit(const char **s)
{
	int		start;
	int		ind;
	int		count;
	char	***tab;

	start = 0;
	count = 0;
	ind = 0;
	tab = (char ***) malloc(sizeof(char **) * nb_part(s));
	while (s[count])
	{
		while(ft_strcmp(s[count], ";") == 0 && s[count])
			count++;
		if (s[count] == '\0')
			return (tab);
		start = count;
		while (ft_strcmp(s[count], ";") != 0 && s[count])
			count++;
		tab[ind] = ft_tabsub(s, start, count - start);
		ind++;
	}
	tab[ind] = NULL;
	return (tab);
}