#include "../../inc/parser.h"
#include "../../inc/geometry.h"
#include "../../libs/libft/libft.h"
#include <stdlib.h>

void	parse_light(char **line, t_scene *scene)
{
	t_light		*light;
	t_list		*new_light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		ft_error(1, "malloc", "memory allocation failure");
	light->point = atovec3(line[1]);
	light->ratio = ft_atof(line[2]);
	check_vec3(0.0, 1.0, (t_vec3){light->ratio}, "L: ratio [0.0,1.0]");
	light->color = atovec3(line[3]) * light->ratio;
	check_vec3(0, 255, light->color, "L: RGB [0-255]");
	new_light = ft_lstnew((void *)light);
	ft_lstadd_front(&(scene->light), new_light);
}
