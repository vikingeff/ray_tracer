/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 16:07:16 by brehaili          #+#    #+#             */
/*   Updated: 2014/02/12 16:07:18 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

t_point		vector_minus(t_point a, t_point b)
{
	t_point		p;

	p.x = a.x - b.x;
	p.y = a.y - b.y;
	p.z = a.z - b.z;
	return (p);
}

t_point		vector_add(t_point a, t_point b)
{
	return ((t_point){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_line		new_line(t_point a, t_point b)
{
	t_line	line;

	line.pos.x = a.x;
	line.pos.y = a.y;
	line.pos.z = a.z;
	line.ori.x = b.x - a.x;
	line.ori.y = b.y - a.y;
	line.ori.z = b.z - a.z;
	line.ori = norm(line.ori);
	return (line);
}

t_point		vector_add_mult(t_point	a, double i, t_point b)
{
	t_point		p;

	p.x = a.x + i * b.x;
	p.y = a.y + i * b.y;
	p.z = a.z + i * b.z;
	return (p);
}

int		v_equal(t_point a, t_point b)
{
	if (a.x != b.x)
		return (0);
	if (a.y != b.y)
		return (0);
	if (a.z != b.z)
		return (0);
	return (1);
}