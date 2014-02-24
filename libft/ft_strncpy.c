/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:09:37 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:36:15 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	len;

	if (n <= 0)
		return (s1);
	len = ft_strlen(s2);
	if (len >= n)
		ft_memcpy(s1, s2, n);
	else
	{
		ft_memcpy(s1, s2, len);
		ft_memset(s1 + len, 0, n - len);
	}
	return (s1);
}
