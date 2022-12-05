#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "geometry.h"
# include "scene_structs.h"
# include "shape_structs.h"

typedef struct s_ray
{
	t_point	origin;
	t_vec3	direction;
}			t_ray;

typedef struct s_hitpoint
{
	t_point	point;
	t_vec3	normal;
}			t_hitpoint;

void	cast_camera_ray(int x, int y, t_scene scene, t_color *pixelcolor);
void	cast_shadow_ray(t_hitpoint hit, t_scene scene, t_ray cam_ray, \
						t_color *pixelcolor);
bool	trace(t_ray ray, t_object *objects, t_object **hitobj, float *tnear);

#endif