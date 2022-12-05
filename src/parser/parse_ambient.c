#include "../../inc/parser.h"
#include "../../libs/libft/libft.h"

void	parse_ambient(char **line, t_scene *scene)
{
	float	ratio;
	t_color	rgb_color;

	ratio = ft_atof(line[1]);
	rgb_color = atovec3(line[2]);
	check_vec3(0.0, 1.0, (t_vec3){ratio}, "A: ratio [0.0,1.0]");
	check_vec3(0, 255, rgb_color, "A: RGB [0-255]");
	scene->ambient = rgb_color * ratio;
}
