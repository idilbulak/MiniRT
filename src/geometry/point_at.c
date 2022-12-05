#include "../../inc/geometry.h"
#include "../../inc/raytracer.h"

t_vec3	point_at(t_ray ray, float distance)
{
	return (ray.origin + ray.direction * distance);
}
