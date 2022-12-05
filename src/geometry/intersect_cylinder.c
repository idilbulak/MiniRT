#include "../../inc/raytracer.h"
#include <stdbool.h>
#include <math.h>

static float	delimit(t_cylinder cy, t_ray ray, float r)
{
	t_point	point;
	t_vec3	point2;

	point = cy.center + cy.direction * cy.height;
	point2 = point_at(ray, r) - point;
	if (dot(point2, cy.direction) / magnitude(point2) > 0)
		return (0);
	point2 = point_at(ray, r) - cy.center;
	if (dot(point2, cy.direction) / magnitude(point2) < 0)
		return (0);
	return (r);
}

static float	intersect_body(t_cylinder cy, t_ray ray)
{
	t_vec3	vec1;
	t_vec3	vec2;
	float	coef[3];
	float	r;

	vec1 = cross(ray.direction, cy.direction);
	coef[0] = dot(vec1, vec1);
	vec2 = cross(ray.origin - cy.center, cy.direction);
	coef[1] = dot(vec1, vec2) * 2;
	coef[2] = dot(vec2, vec2) - powf(cy.radius, 2);
	r = quadratic(coef);
	return (delimit(cy, ray, r));
}

float	finddisc(t_cylinder cy, t_ray ray, t_point center)
{
	float		disc;
	t_vec3		point;
	t_object	obj;

	obj.shape.pl.direction = cy.direction;
	obj.shape.pl.center = center;
	intersect_plane(&obj, ray, &disc);
	point = point_at(ray, disc);
	if (dot(center - point, center - point) > powf(cy.radius, 2))
		disc = 0;
	return (disc);
}

static float	intersect_disc(t_cylinder cy, t_ray ray)
{
	float	disc1;
	float	disc2;

	disc1 = finddisc(cy, ray, cy.center);
	disc2 = finddisc(cy, ray, cy.center + cy.direction * cy.height);
	return (findmin(disc1, disc2));
}

bool	intersect_cylinder(t_object *obj, t_ray ray, float *t)
{
	float	r1;
	float	r2;

	r1 = intersect_disc(obj->shape.cy, ray);
	r2 = intersect_body(obj->shape.cy, ray);
	*t = findmin(r1, r2);
	return (*t > 0);
}
