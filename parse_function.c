/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:13:35 by brehaili          #+#    #+#             */
/*   Updated: 2014/02/03 16:13:37 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft/libft.h"
#include "rtv1.h"

extern t_fun	keyword[6];

void	fill_camera(t_env *env, char **tab)
{
	char	**split;
	double	norme;

	split = ft_strsplit(tab[1], ',');
	env->cam_pos.x = ft_atoi(split[0] + 1);
	env->cam_pos.y = ft_atoi(split[1]);
	env->cam_pos.z = ft_atoi(split[2]);
	ft_strsplit_clr(split);
	split = ft_strsplit(tab[2], ',');
	env->cam_ori.x = ft_atoi(split[0] + 1);
	env->cam_ori.y = ft_atoi(split[1]);
	env->cam_ori.z = ft_atoi(split[2]);
	env->cam_ori = norm(env->cam_ori);
	env->cam_right = vector_cross(env->cam_ori, (t_point){0, 0, 1});
	env->cam_up = vector_cross(env->cam_right, env->cam_ori);
	ft_strsplit_clr(split);
}

int		hex_to_i(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res += (str[i] - '0') * pow(16, 7 - i);
		else
			res += (str[i] - 'A' + 10) * pow(16, 7 - i);
		i++;
	}
	return (res);
}

void	fill_color(t_env *env, char **tab)
{
	env->color = hex_to_i(tab[1]);
	env->intensity = ft_atoi(tab[2]) / 100.0;
}

void	add_sphere(t_env *env, char **tab)
{
	t_point		p;
	t_list		*list;
	char		**split;

	split = ft_strsplit(tab[1], ',');
	p.x = ft_atoi(split[0] + 1);
	p.y = ft_atoi(split[1]);
	p.z = ft_atoi(split[2]);
	list = new_list(p, hex_to_i(tab[3]));
	list->name = "sphere";
	list->radius = ft_atoi(tab[2]);
	list->diffuse = ft_atoi(tab[4]) / 100.0;
	list->specular = ft_atoi(tab[5]) / 100.0;
	list->phong = ft_atoi(tab[6]);
	list->fun = &(keyword[2]);
	env->object = add_list_list(env->object, list);
	ft_strsplit_clr(split);
}

void	add_cylinder(t_env *env, char **tab)
{
	t_point		p;
	t_list		*list;
	char		**split;

	split = ft_strsplit(tab[1], ',');
	p.x = ft_atoi(split[0] + 1);
	p.y = ft_atoi(split[1]);
	p.z = ft_atoi(split[2]);
	list = new_list(p, hex_to_i(tab[4]));
	list->name = "cylinder";
	ft_strsplit_clr(split);
	split = ft_strsplit(tab[2], ',');
	list->ori.x = ft_atoi(split[0] + 1);
	list->ori.y = ft_atoi(split[1]);
	list->ori.z = ft_atoi(split[2]);
	list->ori = norm(list->ori);
	list->radius = ft_atoi(tab[3]);
	list->diffuse = ft_atoi(tab[5]) / 100.0;
	list->specular = ft_atoi(tab[6]) / 100.0;
	list->phong = ft_atoi(tab[7]);
	list->fun = &(keyword[3]);
	env->object = add_list_list(env->object, list);
	ft_strsplit_clr(split);
}

void	add_plan(t_env *env, char **tab)
{
	t_point		p;
	t_list		*list;
	char		**split;

	split = ft_strsplit(tab[1], ',');
	p.x = ft_atoi(split[0] + 1);
	p.y = ft_atoi(split[1]);
	p.z = ft_atoi(split[2]);
	list = new_list(p, hex_to_i(tab[4]));
	list->name = "plan";
	ft_strsplit_clr(split);
	split = ft_strsplit(tab[2], ',');
	list->ori.x = ft_atoi(split[0] + 1);
	list->ori.y = ft_atoi(split[1]);
	list->ori.z = ft_atoi(split[2]);
	list->ori = norm(list->ori);
	ft_strsplit_clr(split);
	split = ft_strsplit(tab[3], ',');
	list->ori2.x = ft_atoi(split[0] + 1);
	list->ori2.y = ft_atoi(split[1]);
	list->ori2.z = ft_atoi(split[2]);
	list->ori2 = norm(list->ori2);
	list->diffuse = ft_atoi(tab[5]) / 100.0;
	list->specular = ft_atoi(tab[6]) / 100.0;
	list->phong = ft_atoi(tab[7]);
	list->fun = &(keyword[4]);
	env->object = add_list_list(env->object, list);
	ft_strsplit_clr(split);
}

void	add_light(t_env *env, char **tab)
{
	t_point		p;
	t_list		*list;
	char		**split;

	split = ft_strsplit(tab[1], ',');
	p.x = ft_atoi(split[0] + 1);
	p.y = ft_atoi(split[1]);
	p.z = ft_atoi(split[2]);
	ft_strsplit_clr(split);
	list = new_list(p, hex_to_i(tab[2]));
	list->name = "light";
	list->intensity = ft_atoi(tab[3]) / 100;
	env->light = add_list_list(env->light, list);
}