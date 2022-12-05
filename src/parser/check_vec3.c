#include "../../inc/geometry.h"
#include "../../libs/libft/libft.h"

t_vec3	check_vec3(float min, float max, t_vec3 input, char *str)
{
	if (input[0] > max || input[1] > max || input[2] > max
		|| input[0] < min || input[1] < min || input[2] < min)
		ft_error(1, "parser: invalid range", str);
	return (input);
}
