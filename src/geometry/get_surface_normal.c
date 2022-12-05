#include "../../inc/geometry.h"
#include "../../inc/raytracer.h"

t_vec3	get_sphere_normal(t_object hitobj, t_hitpoint hit)
{
	return (normalize(hit.point - hitobj.shape.sp.center));
}

t_vec3	get_plane_normal(t_object hitobj, t_hitpoint hit)
{
	(void)hit;
	return (normalize(hitobj.shape.pl.direction));
}

t_vec3	get_cylinder_normal(t_object hitobj, t_hitpoint hit)
{
	t_vec3	perpen_at;
	float	perpen;

	perpen = dot(hit.point - hitobj.shape.cy.center, hitobj.shape.cy.direction) \
		/ dot(hitobj.shape.cy.direction, hitobj.shape.cy.direction);
	perpen_at = hitobj.shape.cy.center + hitobj.shape.cy.direction * perpen;
	if (perpen <= 0.00001)
		return (hitobj.shape.cy.direction * -1);
	else if (perpen >= hitobj.shape.cy.height - 0.00001)
		return (hitobj.shape.cy.direction);
	else
		return (normalize(hit.point - perpen_at));
}

t_vec3	get_cone_normal(t_object hitobj, t_hitpoint hit)
{
	t_vec3	cp;
	t_vec3	n;

	if (dot(hit.point - (hitobj.shape.cn.center
				+ hitobj.shape.cn.direction * hitobj.shape.cn.height), \
		hitobj.shape.cn.direction * -1) <= 0.001)
		return (hitobj.shape.cn.direction);
	else
	{
		cp = hit.point - (hitobj.shape.cn.center);
		n = normalize(cp * dot(hitobj.shape.cn.direction, cp)
				/ dot(cp, cp) - hitobj.shape.cn.direction);
		return (n);
	}
}
