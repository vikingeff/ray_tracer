/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:41:06 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:36:31 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	count;

	ret = (char *) malloc(size + 1);
	if (ret == NULL)
		return (ret);
	count = 0;
	while (count <= size)
	{
		ret[count] = '\0';
		count++;
	}
	return (ret);
}
