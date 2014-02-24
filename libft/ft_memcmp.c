/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:33:29 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:31:40 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n <= 0)
		return (0);
	count = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (count < n - 1 && (str1[count] == str2[count]))
		count++;
	return (str1[count] - str2[count]);
}
