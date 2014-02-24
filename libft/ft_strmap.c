/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:41:09 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:35:31 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		ret[count] = (*f)(s[count]);
		count++;
	}
	return (ret);
}
