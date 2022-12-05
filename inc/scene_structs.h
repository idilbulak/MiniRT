#ifndef SCENE_STRUCTS_H
# define SCENE_STRUCTS_H

# include "../libs/libft/libft.h"
# include "geometry.h"
# include "shape_structs.h"
# include <stdbool.h>

typedef struct s_object	t_object;

typedef struct s_light
{
	t_point	point;
	t_color	color;
	float	ratio;
}			t_light;

typedef struct s_camera
{
	t_point	lookfrom;
	t_point	lower_left_corner;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	direction;
	float	fov;
	float	focallen;
}			t_camera;

typedef struct s_object
{
	t_color		color;
	t_shape		shape;
	bool		(*intersect)(struct s_object*, struct s_ray, float *t);
	t_vec3		(*get_surface_normal)(t_object hitobj, t_hitpoint hit);
	t_object	*next;
}				t_object;

typedef struct s_scene
{
	t_color		ambient;
	t_camera	camera;
	t_list		*light;
	t_object	*objects;
}				t_scene;

#endif