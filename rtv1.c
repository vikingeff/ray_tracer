/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 13:03:29 by brehaili          #+#    #+#             */
/*   Updated: 2014/02/27 21:52:48 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft/libft.h"
#include <mlx.h>
#include <math.h>

int		color_diffuse(t_env *env, t_list *list, t_point p)
{
	int		color;
	t_list	*tmp;
	t_point	normal;

	normal = list->fun->func_normal(list, p);
	tmp = env->light;
	color = 0;
	while (tmp)
	{
		if (!is_obstacle(new_line(p, tmp->pos), list, env))
			color = add_color(color, multiply_color(list->color, \
				tmp->intensity * vector_multiply(normal, \
				vector_direc(p, tmp->pos))));
		tmp = tmp->next;
	}
	color = multiply_color(color, list->diffuse);
	return (color);
}

int		color_specular(t_env *env, t_list *list, t_point p)
{
	int		color;
	t_list	*tmp;
	t_point	normal;
	t_point	bissect;

	normal = list->fun->func_normal(list, p);
	tmp = env->light;
	color = 0;
	while (tmp)
	{
		if (!is_obstacle(new_line(p, tmp->pos), list, env))
		{
			bissect = bissectant(normal, vector_direc(p, tmp->pos));
			color = add_color(color, multiply_color(0x00FFFFFF, \
				pow(vector_multiply(normal, bissect), list->phong) \
				* tmp->intensity));
		}
		tmp = tmp->next;
	}
	color = multiply_color(color, list->specular);
	return (color);
}

int		is_obstacle(t_line line, t_list *me, t_env *env)
{
	t_list	*tmp;

	tmp = env->object;
	while (tmp)
	{
		if (tmp != me && vector_multiply(vector_minus(tmp->fun->\
				func_inter(line, tmp), line.pos), line.ori) > 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		one_ray(t_env *env, t_line line)
{
	t_list	*tmp;
	//t_fun	*object;
	t_point	p;

	tmp = env->object;
	while (tmp)
	{
		if (v_equal(p = tmp->fun->func_inter(line, tmp), env->cam_pos) != 1)
		{
			return (add_color_3(multiply_color(tmp->color, tmp->diffuse * \
				env->intensity), color_diffuse(env, tmp, p), \
				color_specular(env, tmp, p)));
		}
		tmp = tmp->next;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		ft_exit("Incorrect argument's number\n");
	env = init(av[1]);
	raytracing(env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
