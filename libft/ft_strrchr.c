/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:14:49 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:36:44 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	occ;
	int		count;
	char	*str;

	count = ft_strlen(s);
	occ = (char) c;
	str = (char *) s;
	while (s[count] != occ && (count != 0))
		count--;
	if (s[count] == occ)
		return (str + count);
	return (NULL);
}
