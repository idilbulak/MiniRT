#include "../../inc/parser.h"
#include "../../inc/geometry.h"
#include "../../inc/miniRT.h"
#include "../../libs/libft/libft.h"
#include <math.h>

void	parse_camera(char **line, t_scene *scene)
{
	float	fov;

	fov = ft_atof(line[3]);
	scene->camera.lookfrom = atovec3(line[1]);
	scene->camera.direction = atovec3(line[2]);
	check_vec3(0, 180, (t_vec3){fov}, "C: field of view [0,180]");
	check_vec3(-1.0, 1.0, scene->camera.direction, "C: direction [-1,1]");
	scene->camera.focallen = (float)WIDTH / 2 / tan(fov / 2 * M_PI / 180);
	scene->camera.horizontal = normalize(\
		cross(scene->camera.direction, (t_vec3){0.0, 0.0, -1.0}));
	if (magnitude(cross((t_vec3){0.0, 1.0, 0.0}, scene->camera.direction)))
		scene->camera.horizontal = normalize(\
		cross(scene->camera.direction, (t_vec3){0.0, 1.0, 0.0}));
	scene->camera.vertical = normalize(\
		cross(scene->camera.horizontal, scene->camera.direction));
	scene->camera.lower_left_corner = scene->camera.lookfrom \
		+ scene->camera.direction * scene->camera.focallen;
	scene->camera.lower_left_corner = scene->camera.lower_left_corner \
		+ scene->camera.horizontal * (-((float)WIDTH - 1.0) / 2);
	scene->camera.lower_left_corner = scene->camera.lower_left_corner \
		+ scene->camera.vertical * (-((float)HEIGHT - 1.0) / 2);
}
