/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:54:28 by brehaili          #+#    #+#             */
/*   Updated: 2013/12/09 09:23:45 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	ret = (char *) malloc(sizeof(char) * len + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, len);
	ret[len] = '\0';
	return (ret);
}
