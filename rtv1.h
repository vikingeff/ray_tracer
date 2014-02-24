/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 12:55:49 by brehaili          #+#    #+#             */
/*   Updated: 2014/02/03 12:55:50 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define SCREEN_DIST 1660

typedef struct s_fun	t_fun;
typedef struct s_list	t_list;

typedef struct	s_image
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*data;
	int		color;
}				t_image;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_line
{
	t_point		pos;
	t_point		ori;
}				t_line;

typedef struct	s_sphere
{
	t_point		coord;
	int			radius;
	int			color;
}				t_sphere;

struct		s_list
{
	char			*name;
	t_point			pos;
	t_point			ori;
	t_point			ori2;
	int				radius;
	int				color;
	float			intensity;
	float			diffuse;
	float			specular;
	int				phong;
	t_fun			*fun;
	struct s_list	*next;
};

typedef struct	s_env
{
	t_point		cam_pos;
	t_point		cam_ori;
	t_point		cam_up;
	t_point		cam_right;
	t_point		screen;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*img;
	int			color;
	float		intensity;
	t_list		*object;
	t_list		*light;
}				t_env;

typedef struct	s_solution
{
	double		a;
	double		b;
	double		c;
	double		delta;
	double		t1;
	double		t2;
}				t_solution;

struct	s_fun
{
	char	*name;
	void	(*func_add)(t_env *, char **);
	t_point	(*func_inter)(t_line, t_list *);
	t_point (*func_normal)(t_list *, t_point);
};

int				get_next_line(const int fd, char **line);
t_image			*new_t_image(void *mlx_ptr, int size_x, int size_y);
void			clean_image(t_env *env);
void			put_pixel_t_image(t_image *img, int x, int y, int color);
t_env			*init(char *str);
void			parse_file(t_env *env, char *str);
void			fill_env(t_env *env, char **tab);
void			fill_camera(t_env *env, char **tab);
int				hex_to_i(char *str);
void			fill_color(t_env *env, char **tab);
void			add_sphere(t_env *env, char **tab);
t_list			*new_list(t_point p, int color);
t_list			*add_list(t_list *head, t_point p, int color);
t_fun			*search_object(char *name);
t_list			*add_list_list(t_list *head, t_list *list);
int				one_ray(t_env *env, t_line line);
t_point			sphere_inter(t_line line, t_list *list);
void			add_light(t_env *env, char **tab);
t_point			sphere_normal(t_list *list, t_point point);
t_point			bissectant(t_point n, t_point l);
t_point			norm(t_point a);
t_point			vector_cross(t_point a, t_point b);
double			vector_multiply(t_point a, t_point b);
t_point			vector_direc(t_point a, t_point b);
t_point			vector_minus(t_point a, t_point b);
t_point			vector_add_mult(t_point	a, double i, t_point b);
int				add_color(int color1, int color2);
int				add_color_3(int color1, int color2, int color3);
int				v_equal(t_point a, t_point b);
t_point			cylinder_normal(t_list *list, t_point point);
t_point			cylinder_inter(t_line line, t_list *list);
void			add_cylinder(t_env *env, char **tab);
t_point			plan_normal(t_list *list, t_point point);
t_point			plan_inter(t_line line, t_list *list);
void			add_plan(t_env *env, char **tab);
int				is_obstacle(t_line line, t_list *me, t_env *env);
t_line			new_line(t_point a, t_point b);
void			raytracing(t_env *env);
int				multiply_color(int color, double multi);
int				expose_hook(void *param);
int				key_hook(int keycode, void *param);
void			clean_image(t_env *env);

#endif /* !RTV1_H */