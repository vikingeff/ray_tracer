/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:36:56 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:35:59 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		len_s1;
	size_t		len_s2;

	if (n <= 0)
		return (s1);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s2 < n)
	{
	ft_memcpy(s1 + len_s1, s2, len_s2);
		s1[len_s1 + len_s2] = '\0';
	}
	else
	{
		ft_memcpy(s1 + len_s1, s2, n);
		s1[len_s1 + n] = '\0';
	}
	return (s1);
}
