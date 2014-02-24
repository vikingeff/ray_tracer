/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 20:00:17 by brehaili          #+#    #+#             */
/*   Updated: 2014/02/13 20:00:19 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		add_color(int color1, int color2)
{
	int		color;
	int		tmp;
	int		i;

	i = 0;
	color = 0;
	while (i < 4)
	{
		tmp = ((color1 & (0xFF << (i * 8))) >> (i * 8)) \
			+ ((color2 & (0xFF << (i * 8))) >> (i * 8));
		if (tmp > 255)
			tmp = 255;
		color += (tmp << (i * 8));
		i++;
	}
	return (color);
}

int		add_color_3(int color1, int color2, int color3)
{
	int		color;
	int		tmp;
	int		i;

	i = 0;
	color = 0;
	while (i < 4)
	{
		tmp = ((color1 & (0xFF << (i * 8))) >> (i * 8)) \
			+ ((color2 & (0xFF << (i * 8))) >> (i * 8)) \
			+ ((color3 & (0xFF << (i * 8))) >> (i * 8));
		if (tmp > 255)
			tmp = 255;
		color += (tmp << (i * 8));
		i++;
	}
	return (color);
}