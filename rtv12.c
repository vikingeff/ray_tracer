/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv12.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:44:16 by brehaili          #+#    #+#             */
/*   Updated: 2014/02/16 17:44:18 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft/libft.h"
#include <mlx.h>
#include <math.h>


t_line	new_t_line(t_point a, t_point b)
{
	t_line	line;
	int		norme;

	line.pos.x = a.x;
	line.pos.y = a.y;
	line.pos.z = a.z;
	line.ori.x = b.x - a.x;
	line.ori.y = b.y - a.y;
	line.ori.z = b.z - a.z;
	norme = sqrt(line.ori.x * line.ori.x + line.ori.y * line.ori.y + \
		line.ori.z * line.ori.z);
	line.ori.x /= norme;
	line.ori.y /= norme;
	line.ori.z /= norme;
	return (line);
}

t_point	first_screen(t_env *env)
{
	t_point		p;

	p.x = env->cam_pos.x + env->screen.z * env->cam_ori.x \
		- ((env->screen.x / 2) * env->cam_right.x) \
		+ ((env->screen.y / 2) * env->cam_up.x);
	p.y = env->cam_pos.y + env->screen.z * env->cam_ori.y \
		- ((env->screen.x / 2) * env->cam_right.y) \
		+ ((env->screen.y / 2) * env->cam_up.y);
	p.z = env->cam_pos.z + env->screen.z * env->cam_ori.z \
		- ((env->screen.x / 2) * env->cam_right.z) \
		+ ((env->screen.y / 2) * env->cam_up.z);
	return (p);
}

void	raytracing(t_env *env)
{
	int		x;
	int		y;
	int		color;
	t_point	first;
	t_point	reset;

	first = first_screen(env);
	reset = first;
	x = 0;
	clean_image(env);
	while (x < env->screen.x)
	{
		y = 0;
		first = reset;
		first = vector_add_mult(first, x, env->cam_right);
		while (y < env->screen.y)
		{
			if ((color = one_ray(env, new_t_line(env->cam_pos, first))) != 0)
				put_pixel_t_image(env->img, x, y, color);
			first = vector_minus(first, env->cam_up);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, \
		env->img->img_ptr, 0, 0);
}

int		multiply_color(int color, double multi)
{
	int		res;

	res = 0;
	if (multi >= 0)
	{
		res += (int)((int)((color & 0x00FF0000) >> 16) * multi) << 16;
		res += (int)((int)((color & 0x0000FF00) >> 8) * multi) << 8;
		res += (int)((color & 0x000000FF) * multi);
	}
	return (res);
}