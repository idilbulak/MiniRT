#include "../../inc/raytracer.h"
#include <math.h>

static t_vec3	get_specular_color(t_hitpoint hit, t_light *light, \
	t_ray cam_ray, t_ray shadowray)
{
	t_vec3	spec_dir;
	float	specular;

	spec_dir = cam_ray.direction - hit.normal * 2.0f
		* dot(cam_ray.direction, hit.normal);
	specular = fmaxf(0.f, dot(spec_dir, shadowray.direction));
	specular /= magnitude(shadowray.direction);
	specular = powf(specular, 4);
	return (light->color * specular * 0.4f);
}

static t_vec3	get_diffuse_color(t_hitpoint hit, t_light *light, \
	t_ray shadowray)
{
	float	diffuse;

	diffuse = fmaxf(0.f, dot(hit.normal, shadowray.direction));
	diffuse /= magnitude(shadowray.direction);
	if (diffuse < 0)
		diffuse *= -1;
	return (light->color * diffuse * 0.4f);
}

void	cast_shadow_ray(t_hitpoint hit, t_scene scene, t_ray cam_ray, \
	t_color *pixelcolor)
{
	t_object	*shadowobj;
	t_light		*light;
	t_ray		shadowray;
	float		tshadow;
	float		light_distance;

	while (scene.light)
	{
		shadowobj = NULL;
		tshadow = INFINITY;
		light = (t_light *)scene.light->content;
		shadowray.origin = hit.point;
		shadowray.direction = normalize(light->point - hit.point);
		light_distance = magnitude(light->point - hit.point);
		if ((!trace(shadowray, scene.objects, &shadowobj, &tshadow)
				&& light_distance != 0) || tshadow > light_distance)
		{
			*pixelcolor += get_diffuse_color(hit, light, shadowray);
			*pixelcolor += get_specular_color(hit, light, cam_ray, shadowray);
		}
		scene.light = scene.light->next;
	}
}
