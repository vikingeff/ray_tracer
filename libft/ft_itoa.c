/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:31:10 by brehaili          #+#    #+#             */
/*   Updated: 2013/12/09 10:36:36 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		len;
	char	*ret;
	int		count;

	count = 0;
	len = ft_nb_digit(n);
	if (n < 0)
	{
		ret = ft_strnew(len + 1);
		ret[0] = '-';
		count++;
		n = -n;
	}
	else
		ret = ft_strnew(len);
	if (ret == NULL)
		return (ret);
	while (len > 0)
	{
		len--;
		ret[count] = '0' + (n / ft_pow(10, len)) % 10;
		count++;
	}
	return (ret);
}
