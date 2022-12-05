#include "../../inc/raytracer.h"
#include <math.h>

static void	set_camera_ray(int x, int y, t_camera camera, t_ray *cam_ray)
{
	cam_ray->origin = camera.lookfrom;
	cam_ray->direction = normalize(camera.lower_left_corner
			+ camera.horizontal * (float)x
			+ camera.vertical * (float)y);
}

void	cast_camera_ray(int x, int y, t_scene scene, t_color *pixelcolor)
{
	t_object	*hitobj;
	t_hitpoint	hitpoint;
	t_ray		cam_ray;
	float		tnear;

	hitobj = NULL;
	tnear = INFINITY;
	*pixelcolor = (t_vec3){0.0, 0.0, 0.0};
	set_camera_ray(x, y, scene.camera, &cam_ray);
	if (trace(cam_ray, scene.objects, &hitobj, &tnear))
	{
		hitpoint.point = point_at(cam_ray, tnear);
		hitpoint.normal = hitobj->get_surface_normal(*hitobj, hitpoint);
		cast_shadow_ray(hitpoint, scene, cam_ray, pixelcolor);
		*pixelcolor += scene.ambient * 0.2f;
		*pixelcolor *= (hitobj->color / 255);
	}
}
