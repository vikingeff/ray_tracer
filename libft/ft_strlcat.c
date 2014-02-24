/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:48:14 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 20:39:21 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	if (size <= len_dst)
		return (size + ft_strlen(src));
	ft_strncpy(dst + len_dst, src, size - len_dst - 1);
	dst[size] = '\0';
	return (len_dst + ft_strlen(src));
}
