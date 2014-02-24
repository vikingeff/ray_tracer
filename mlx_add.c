/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 17:15:36 by brehaili          #+#    #+#             */
/*   Updated: 2013/12/20 15:50:45 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/libft.h"
#include "rtv1.h"

t_image		*new_t_image(void *mlx_ptr, int size_x, int size_y)
{
	t_image	*img;

	if ((img = (t_image *)malloc(sizeof(t_image))) == NULL)
		return (NULL);
	img->img_ptr = mlx_new_image(mlx_ptr, size_x, size_y);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bits_per_pixel),
		&(img->size_line), &(img->endian));
	img->color = 255;
	return (img);
}

void	clean_image(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->screen.y)
	{
		j = 0;
		while (j < env->screen.x)
		{
			put_pixel_t_image(env->img, j, i, 0);
			j++;
		}
		i++;
	}
}

void	put_pixel_t_image(t_image *img, int x, int y, int color)
{
	img->data[y * img->size_line + x * 4] = (color & 0x000000FF);
	img->data[y * img->size_line + x * 4 + 1] = (color & 0x0000FF00) >> 8;
	img->data[y * img->size_line + x * 4 + 2] = (color & 0x00FF0000) >> 16;
	img->data[y * img->size_line + x * 4 + 3] = (color & 0xFF000000) >> 24;
}