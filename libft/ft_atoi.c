/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:14:07 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/27 14:06:18 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		count;
	int		res;
	int		sign;

	count = 0;
	res = 0;
	sign = 1;
	while (str[count] == ' ' || str[count] == '\t' || str[count] == '\n')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (str[count])
	{
		if (!ft_isdigit(str[count]))
			return (res * sign);
		res = res * 10;
		res = res + str[count] - '0';
		count++;
	}
	return (res * sign);
}
