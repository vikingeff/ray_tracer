/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:38:36 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 19:22:15 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			count;
	unsigned char	*str1;
	unsigned char	*str2;

	count = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (count < n)
	{
		str1[count] = str2[count];
		if (str1[count] == (unsigned char) c)
			return (s1 + count + 1);
		count++;
	}
	return (NULL);
}
