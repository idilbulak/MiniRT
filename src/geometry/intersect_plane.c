#include "../../inc/raytracer.h"
#include <stdbool.h>

bool	intersect_plane(t_object *obj, t_ray ray, float *t)
{
	float	r;

	if (dot(obj->shape.pl.direction, ray.direction) > 0)
		obj->shape.pl.direction = obj->shape.pl.direction * -1;
	r = dot(obj->shape.pl.direction, obj->shape.pl.center - ray.origin) / \
		dot(obj->shape.pl.direction, ray.direction);
	*t = findmin(r, 0);
	return (*t > 0);
}
