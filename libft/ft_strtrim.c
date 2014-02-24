/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:56:32 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/26 18:37:12 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		len;
	int		start;
	int		end;
	char	*ret;

	len = ft_strlen(s);
	start = 0;
	end = len - 1;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			&& start < len)
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			&& end > start)
		end--;
	ret = ft_strnew(end - start + 1);
	if (ret == NULL)
		return (ret);
	ft_memcpy(ret, s + start, end - start + 1);
	return (ret);
}
