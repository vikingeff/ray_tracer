/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:08:08 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:33:23 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	occ;
	size_t	count;
	char	*str;
	size_t	len;

	len = ft_strlen(s) + 1;
	count = 0;
	occ = (char) c;
	str = (char *) s;
	while (s[count] != occ && (count < len))
		count++;
	if (s[count] == occ)
		return (str + count);
	return (NULL);
}
