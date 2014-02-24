/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:03:37 by brehaili          #+#    #+#             */
/*   Updated: 2013/11/21 16:05:30 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(const char *s)
{
	int		count;

	count = 0;
	if (s == NULL)
		ft_putstr("(null)");
	while (s[count])
	{
		ft_putchar(s[count]);
		count++;
	}
}
