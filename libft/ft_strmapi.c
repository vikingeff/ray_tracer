/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:47:42 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:35:38 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	size_t		count;
	char		*ret;

	count = 0;
	len = ft_strlen(s);
	ret = (char *) malloc(len);
	if (ret == NULL)
		return (ret);
	while (count < len)
	{
		ret[count] = (*f)(count, s[count]);
		count++;
	}
	return (ret);
}
