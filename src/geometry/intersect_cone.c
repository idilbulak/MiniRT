#include "../../inc/raytracer.h"
#include <stdbool.h>
#include <math.h>

static float	checkt_cn(t_cone *cn, t_ray ray, t_vec3 h, float t)
{
	t_vec3	d;

	d = ray.origin + ray.direction * t;
	if (!(0 <= dot(d - cn->center, cn->direction) \
			&& dot(d - cn->center, cn->direction) <= magnitude(h)))
		return (0);
	return (t);
}

static float	intersect_body_cone(t_cone *cn, t_ray ray, float qdt[3])
{
	t_vec3	h;
	float	discriminant;
	float	t1;
	float	t2;

	discriminant = powf(qdt[1], 2) - qdt[0] * qdt[2];
	h = cn->direction * cn->height;
	t1 = (-qdt[1] - sqrtf(discriminant)) / qdt[0];
	t1 = checkt_cn(cn, ray, h, t1);
	t2 = (-qdt[1] + sqrtf(discriminant)) / qdt[0];
	t2 = checkt_cn(cn, ray, h, t2);
	return (findmin(t1, t2));
}

static float	intersect_disc_cone(t_cone *cn, t_ray ray)
{
	t_cylinder	cy;
	t_vec3		h;

	h = cn->center + cn->direction * cn->height;
	cy.direction = cn->direction;
	cy.center = h;
	cy.radius = cn->radius;
	return (finddisc(cy, ray, h));
}

bool	intersect_cone(t_object *obj, t_ray ray, float *t)
{
	t_cone	*cn;
	t_vec3	x;
	float	k;
	float	qdt[3];
	float	t_temp[2];

	cn = &obj->shape.cn;
	x = ray.origin - cn->center;
	k = powf(cn->radius, 2) / powf(cn->height, 2);
	qdt[0] = dot(ray.direction, ray.direction) \
		- (k + 1) * dot(ray.direction, cn->direction) \
		* dot(ray.direction, cn->direction);
	qdt[1] = dot(ray.direction, x) \
		- (k + 1) * dot(ray.direction, cn->direction) \
		* dot(x, cn->direction);
	qdt[2] = dot(x, x) \
		- (k + 1) * dot(x, cn->direction) * dot(x, cn->direction);
	if (powf(qdt[1], 2) - qdt[0] * qdt[2] < 0)
		return (false);
	t_temp[0] = intersect_disc_cone(cn, ray);
	t_temp[1] = intersect_body_cone(cn, ray, qdt);
	*t = findmin(t_temp[0], t_temp[1]);
	return (*t > 0.001);
}
