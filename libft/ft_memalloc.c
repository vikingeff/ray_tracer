/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:35:26 by brehaili          #+#    #+#             */
/*   Updated: 2013/12/11 11:40:56 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ret;
	size_t	count;

	ret = (char *)malloc(size);
	if (ret == NULL)
		return (ret);
	count = 0;
	while (count < size)
	{
		ret[count] = 0;
		count++;
	}
	return (ret);
}
