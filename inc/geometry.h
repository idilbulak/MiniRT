#ifndef GEOMETRY_H
# define GEOMETRY_H

# include <stdbool.h>

typedef float				t_vec3 __attribute__ ((vector_size (16)));
typedef t_vec3				t_color;
typedef t_vec3				t_point;

typedef struct s_object		t_object;
typedef struct s_cylinder	t_cylinder;
typedef struct s_hitpoint	t_hitpoint;
typedef struct s_ray		t_ray;

t_vec3	get_sphere_normal(t_object hitobj, t_hitpoint hit);
t_vec3	get_plane_normal(t_object hitobj, t_hitpoint hit);
t_vec3	get_cylinder_normal(t_object hitobj, t_hitpoint hit);
t_vec3	get_cone_normal(t_object hitobj, t_hitpoint hit);

bool	intersect_sphere(t_object *obj, t_ray ray, float *t);
bool	intersect_plane(t_object *obj, t_ray ray, float *t);
bool	intersect_cylinder(t_object *obj, t_ray ray, float *t);
bool	intersect_cone(t_object *obj, t_ray ray, float *t);

t_vec3	point_at(t_ray ray, float distance);
t_vec3	normalize(t_vec3 v);
t_vec3	cross(t_vec3 u, t_vec3 v);

float	dot(t_vec3 u, t_vec3 v);
float	magnitude(t_vec3 v);
float	quadratic(float coef[3]);
float	finddisc(t_cylinder cy, t_ray ray, t_point center);
float	findmin(float r1, float r2);

#endif