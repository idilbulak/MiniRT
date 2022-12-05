#ifndef SHAPE_STRUCT_H
# define SHAPE_STRUCT_H

# include "geometry.h"

typedef struct s_sphere
{
	t_point	center;
	float	radius;
}			t_sphere;

typedef struct s_plane
{
	t_point	center;
	t_vec3	direction;
}			t_plane;

typedef struct s_cylinder
{
	t_point	center;
	t_vec3	direction;
	float	radius;
	float	height;
}			t_cylinder;

typedef struct s_cone
{
	t_point	center;
	t_vec3	direction;
	float	radius;
	float	height;
}			t_cone;

typedef union s_shape
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
	t_cone		cn;
}				t_shape;

#endif