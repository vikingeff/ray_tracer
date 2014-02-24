/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:04:39 by brehaili          #+#    #+#             */
/*   Updated: 2014/02/16 18:04:40 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "rtv1.h"

int		expose_hook(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	mlx_put_image_to_window(env->mlx_ptr,
			env->win_ptr, env->img->img_ptr, 0, 0);
	return (0);
}

int		key_hook(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == 65307)
	{
		exit(0);
	}
	if (keycode == 119)
	{
		env->cam_pos = vector_add_mult(env->cam_pos, 10, env->cam_ori);
		raytracing(env);
	}
	else if (keycode == 115)
	{
		env->cam_pos = vector_add_mult(env->cam_pos, -10, env->cam_ori);
		raytracing(env);
	}
	else if (keycode == 97)
	{
		env->cam_pos = vector_add_mult(env->cam_pos, -10, env->cam_right);
		raytracing(env);
	}
	else if (keycode == 100)
	{
		env->cam_pos = vector_add_mult(env->cam_pos, 10, env->cam_right);
		raytracing(env);
	}
	return (0);
}