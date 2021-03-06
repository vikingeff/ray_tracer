/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 10:34:55 by brehaili          #+#    #+#             */
/*   Updated: 2013/12/09 11:18:06 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nb_digit(int n)
{
	int		len;

	if (n < 0)
		n = -n;
	len = 0;
	while (n / ft_pow(10, len) >= 1)
		len++;
	if (len == 0)
		len++;
	return (len);
}
