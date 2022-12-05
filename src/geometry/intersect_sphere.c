#include "../../inc/raytracer.h"
#include <stdbool.h>

bool	intersect_sphere(t_object *obj, t_ray ray, float *t)
{
	t_vec3	oc;
	float	coef[3];

	oc = ray.origin - obj->shape.sp.center;
	coef[0] = dot(ray.direction, ray.direction);
	coef[1] = 2.0 * dot(oc, ray.direction);
	coef[2] = dot(oc, oc) - obj->shape.sp.radius * obj->shape.sp.radius;
	*t = quadratic(coef);
	return (*t > 0);
}
