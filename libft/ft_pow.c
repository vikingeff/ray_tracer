/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 10:34:11 by brehaili          #+#    #+#             */
/*   Updated: 2013/12/09 11:08:35 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int n, int p)
{
	int		ret;

	ret = 1;
	if (p == 0)
		return (1);
	while (p > 0)
	{
		ret = ret * n;
		p--;
	}
	return (ret);
}
