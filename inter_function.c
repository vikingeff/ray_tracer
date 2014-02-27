/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 16:58:24 by brehaili          #+#    #+#             */
/*   Updated: 2014/02/27 22:00:32 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "rtv1.h"
#include "libft/libft.h"

t_point		closer_point(t_point ori, t_point a, t_point b)
{
	int		dista;
	int		distb;

	dista = sqrt(pow(a.x - ori.x, 2) + pow(a.y - ori.y, 2) + pow(a.z - ori.z, 2));
	distb = sqrt(pow(b.x - ori.x, 2) + pow(b.y - ori.y, 2) + pow(b.z - ori.z, 2));
	if (dista <= distb)
		return (a);
	else
		return (b);
}

t_point		sphere_normal(t_list *list, t_point point)
{
	t_point		p;
	double		norm;

	p.x = point.x - list->pos.x;
	p.y = point.y - list->pos.y;
	p.z = point.z - list->pos.z;
	norm = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	p.x /= norm;
	p.y /= norm;
	p.z /= norm;
	return (p);
}

t_point		cylinder_normal(t_list *list, t_point point)
{
	t_point		normal;
	t_point		tmp;

	tmp = vector_cross(vector_direc(list->pos, point), (t_point){0, 0, 1});
	normal = vector_cross(tmp, (t_point){0, 0, -1});
	normal = norm(normal);
	return (normal);
}

t_point		plan_normal(t_list *list, t_point point)
{
	t_point		normal;

	(void)point;
	normal = vector_cross(list->ori2, list->ori);
	normal = norm(normal);
	return (normal);
}

t_point		cylinder_inter(t_line line, t_list *list)
{
	t_point		n_line;
	double		a;
	double		b;
	double		c;
	double		delta;
	t_point		p1;
	t_point		p2;
	double		t1;
	double		t2;

	n_line = vector_minus(line.pos, list->pos);
	a = line.ori.x * line.ori.x + line.ori.y * line.ori.y;
	b = 2 * n_line.x * line.ori.x + 2 * n_line.y * line.ori.y;
	c = n_line.x * n_line.x + n_line.y * n_line.y \
		- list->radius * list->radius;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (line.pos);
	t1 = (-b + sqrt(delta)) / (2 * a);
	t2 = (-b - sqrt(delta)) / (2 * a);
	p1 = vector_add_mult(line.pos, t1, line.ori);
	p2 = vector_add_mult(line.pos, t2, line.ori);
	return (closer_point(line.pos, p1, p2));
}

t_point		sphere_inter(t_line line, t_list *list)
{
	double		x;
	double		y;
	double		z;
	double		xo;
	double		yo;
	double		zo;
	double		r;
	double		a;
	double		b;
	double		c;
	double		delta;
	double		t1;
	double		t2;
	t_point		p1;
	t_point		p2;

	x = line.pos.x - list->pos.x;
	y = line.pos.y - list->pos.y;
	z = line.pos.z - list->pos.z;
	xo = line.ori.x;
	yo = line.ori.y;
	zo = line.ori.z;
	r = list->radius;
	a = xo * xo + yo * yo + zo * zo;
	b = 2 * x * xo + 2 * y * yo + 2 * z * zo;
	c = x * x + y * y + z * z - r * r;
	delta = pow(2 * x * xo + 2 * y * yo + 2 * z * zo, 2) - 4 \
		* (xo * xo + yo * yo + zo * zo) * (x * x + y * y + z * z - r * r);
	if (delta < 0)
		return (line.pos);
	t1 = (-b + sqrt(delta)) / (2 * a);
	t2 = (-b - sqrt(delta)) / (2 * a);
	p1 = vector_add_mult(line.pos, t1, line.ori);
	p2 = vector_add_mult(line.pos, t2, line.ori);
	return (closer_point(line.pos, p1, p2));
}

t_point		plan_inter(t_line line, t_list *list)
{
	t_solution	s;
	t_point		p;

	s.a = list->ori.y * list->ori2.z - list->ori.z * list->ori2.y;
	s.b = list->ori.z * list->ori2.x - list->ori.x * list->ori2.z;
	s.c = list->ori.x * list->ori2.y - list->ori.y * list->ori2.x;
	s.t1 = (-s.a * (line.pos.x + line.pos.y + line.pos.z) + s.a * list->pos.x \
		+ s.b * list->pos.y + s.c * list->pos.z) / (s.a * (line.ori.x \
		+ line.ori.y + line.ori.z));
	p = vector_add_mult(line.pos, s.t1, line.ori);
	return (line.pos);
}