/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberteau <cberteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:54:02 by cberteau          #+#    #+#             */
/*   Updated: 2014/01/13 14:32:54 by cberteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*ret;

	ret = ft_strnew(len);
	if (ret == NULL)
		return (ret);
	ft_memcpy(ret, s + start, len);
	return (ret);
}
