/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:12:44 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:32:21 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*temp;

	temp = malloc(n);
	ft_memcpy(temp, s2, n);
	ft_memcpy(s1, temp, n);
	free(temp);
	return (s1);
}
