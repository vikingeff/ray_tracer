/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:21:21 by brehaili          #+#    #+#             */
/*   Updated: 2013/12/17 15:41:15 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_part(const char *s, char c)
{
	int		count;
	int		len;

	count = 0;
	len = 0;
	while (s[count])
	{
		while (s[count] == c && s[count])
			count++;
		if (s[count] != '\0')
			len++;
		while (s[count] != c && s[count])
			count++;
	}
	return (len);
}

char		**ft_strsplit(const char *s, char c)
{
	int		start;
	int		ind;
	int		count;
	char	**tab;

	start = 0;
	count = 0;
	ind = 0;
	tab = (char **) malloc(sizeof(char *) * nb_part(s, c) + 1);
	tab[nb_part(s, c)] = '\0';
	while (s[count])
	{
		while (s[count] == c && s[count])
			count++;
		if (s[count] == '\0')
			return (tab);
		start = count;
		while (s[count] != c && s[count])
			count++;
		tab[ind] = ft_strsub(s, start, count - start);
		ind++;
	}
	return (tab);
}
