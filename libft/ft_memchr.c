/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:26:23 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:31:25 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*s2;

	s2 = (unsigned char *) s;
	count = 0;
	while (count < n)
	{
		if (s2[count] == (unsigned char) c)
			return (s2 + count);
		count++;
	}
	return (NULL);
}
