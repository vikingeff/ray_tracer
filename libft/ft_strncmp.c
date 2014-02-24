/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:55:33 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:36:06 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		count;

	if (n <= 0)
		return (0);
	count = 0;
	while (s1[count] == s2[count] && s1[count] != 0 && s2[count] != 0
			&& count < n)
		count++;
	if (count == n)
		return (s1[count - 1] - s2[count - 1]);
	else
		return (s1[count] - s2[count]);
}
