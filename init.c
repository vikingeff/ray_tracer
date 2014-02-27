/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:47:37 by brehaili          #+#    #+#             */
/*   Updated: 2014/02/27 21:59:21 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "rtv1.h"

t_fun	keyword[7] =
{
		{"camera", fill_camera, 0, 0},
		{"background", fill_color, 0, 0},
		{"sphere", add_sphere, sphere_inter, sphere_normal},
		{"cylinder", add_cylinder, cylinder_inter, cylinder_normal},
		{"plan", add_plan, plan_inter, plan_normal},
		{"light", add_light, 0, 0},
		{0, 0, 0, 0}
};

t_fun	*search_object(char *name)
{
	int		i;

	i = 0;
	while (keyword[i].name != NULL)
	{
		if (ft_strcmp(name, keyword[i].name) == 0)
			return (keyword + i);
		i++;
	}
	return (NULL);
}

t_env	*init(char *str)
{
	t_env	*env;

	if ((env = (t_env *)malloc(sizeof(t_env))) == NULL)
		ft_exit("Malloc error.\n");
	env->object = NULL;
	env->screen.x = SCREEN_WIDTH;
	env->screen.y = SCREEN_HEIGHT;
	env->screen.z = SCREEN_DIST;
	parse_file(env, str);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, SCREEN_WIDTH, \
		SCREEN_HEIGHT, "Tadaa");
	env->img = new_t_image(env->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_expose_hook(env->win_ptr, &expose_hook, env);
	mlx_key_hook(env->win_ptr, &key_hook, env);
	return (env);
}

void	parse_file(t_env *env, char *str)
{
	int		fd;
	char	*line;
	char	**split;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		//perror("");
		exit(0);
	}
	while (get_next_line(fd, &line) != 0)
	{
		split = ft_strsplit(line, ' ');
		if (ft_strcmp(line, "") == 0 || ft_strcmp(split[0], "#") == 0)
		{
			ft_strsplit_clr(split);
			free(line);
			continue ;
		}
		fill_env(env, split);
		ft_strsplit_clr(split);
		free(line);
	}
}

void	fill_env(t_env *env, char **tab)
{
	int		i;

	i = 0;
	while (keyword[i].name != NULL)
	{
		if (ft_strcmp(keyword[i].name, tab[0]) == 0)
		{
			keyword[i].func_add(env, tab);
			i = -1;
			break ;
		}
		i++;
	}
	if (i != -1)
		ft_exit("Don't understand your file.\n");
}