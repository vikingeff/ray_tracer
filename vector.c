/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:56:32 by brehaili          #+#    #+#             */
/*   Updated: 2014/02/12 14:56:34 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

t_point		bissectant(t_point n, t_point l)
{
	t_point		bissect;
	double		vect;
	double		norm;

	vect = 2 * vector_multiply(n, l);
	bissect.x = vect * n.x - l.x;
	bissect.y = vect * n.y - l.y;
	bissect.z = vect * n.z - l.z;
	norm = sqrt(bissect.x * bissect.x + bissect.y * bissect.y + bissect.z * bissect.z);
	bissect.x /= norm;
	bissect.y /= norm;
	bissect.z /= norm;
	return (bissect);
}

t_point		norm(t_point a)
{
	double	norm;
	t_point	p;

	p = a;
	norm = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	p.x /= norm;
	p.y /= norm;
	p.z /= norm;
	return (p);
}

t_point		vector_cross(t_point a, t_point b)
{
	t_point	p;

	p.x = a.y * b.z - a.z * b.y;
	p.y = a.z * b.x - a.x * b.z;
	p.z = a.x * b.y - a.y * b.x;
	return (p);
}

double		vector_multiply(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_point		vector_direc(t_point a, t_point b)
{
	t_point	p;
	double		norm;

	p.x = b.x - a.x;
	p.y = b.y - a.y;
	p.z = b.z - a.z;
	norm = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	p.x /= norm;
	p.y /= norm;
	p.z /= norm;
	return (p);
}