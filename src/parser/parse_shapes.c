#include "../../inc/parser.h"
#include "../../inc/raytracer.h"
#include "../../libs/libft/libft.h"
#include <stdlib.h>
#include <float.h>

static void	add_to_objects(t_object **objects, t_object *new)
{
	t_object	*tmp;

	if (*objects == NULL)
		*objects = new;
	else
	{
		tmp = *objects;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	parse_sphere(char **line, t_scene *scene)
{
	t_object		*sphere;

	sphere = malloc(sizeof(t_object));
	if (!sphere)
		ft_error(1, "parser: malloc failed", "t_object");
	sphere->shape.sp.center = atovec3(line[1]);
	sphere->shape.sp.radius = ft_atof(line[2]) / 2.0;
	sphere->color = atovec3(line[3]);
	check_vec3(0, 255, sphere->color, "sp: RGB [0-255]");
	add_to_objects(&(scene->objects), sphere);
	sphere->intersect = &intersect_sphere;
	sphere->get_surface_normal = &get_sphere_normal;
	sphere->next = NULL;
}

void	parse_plane(char **line, t_scene *scene)
{
	t_object	*plane;

	plane = malloc(sizeof(t_object));
	if (!plane)
		ft_error(1, "parser: malloc failed", "t_object");
	plane->shape.pl.center = atovec3(line[1]);
	plane->shape.pl.direction = normalize(atovec3(line[2]));
	plane->color = atovec3(line[3]);
	check_vec3(-1.0, 1.0, plane->shape.pl.direction, "pl:dir[-1.0,1.0]");
	check_vec3(0, 255, plane->color, "pl: RGB [0-255]");
	plane->intersect = &intersect_plane;
	plane->get_surface_normal = &get_plane_normal;
	plane->next = NULL;
	add_to_objects(&(scene->objects), plane);
}

void	parse_cylinder(char **line, t_scene *scene)
{
	t_object		*cylinder;

	cylinder = malloc(sizeof(t_object));
	if (!cylinder)
		ft_error(1, "parser: malloc failed", "t_object");
	cylinder->shape.cy.center = atovec3(line[1]);
	cylinder->shape.cy.direction = normalize(atovec3(line[2]));
	cylinder->shape.cy.radius = ft_atof(line[3]) / 2.0;
	cylinder->shape.cy.height = ft_atof(line[4]);
	cylinder->color = atovec3(line[5]);
	check_vec3(-1.0, 1.0, cylinder->shape.cy.direction, "cy:dir[-1.0,1.0]");
	check_vec3(0, 255, cylinder->color, "cy: RGB [0-255]");
	cylinder->get_surface_normal = &get_cylinder_normal;
	cylinder->intersect = &intersect_cylinder;
	cylinder->next = NULL;
	add_to_objects(&(scene->objects), cylinder);
}

void	parse_cone(char **line, t_scene *scene)
{
	t_object		*cone;

	cone = malloc(sizeof(t_object));
	if (!cone)
		ft_error(1, "parser: malloc failed", "t_object");
	cone->shape.cn.center = atovec3(line[1]);
	cone->shape.cn.direction = normalize(atovec3(line[2]));
	cone->shape.cn.radius = ft_atof(line[3]) / 2.0;
	cone->shape.cn.height = ft_atof(line[4]);
	cone->color = atovec3(line[5]);
	check_vec3(-1.0, 1.0, cone->shape.cn.direction, "cn: direction [-1.0,1.0]");
	check_vec3(0, 255, cone->color, "cn: RGB [0-255]");
	cone->get_surface_normal = &get_cone_normal;
	cone->intersect = &intersect_cone;
	cone->next = NULL;
	add_to_objects(&(scene->objects), cone);
}
