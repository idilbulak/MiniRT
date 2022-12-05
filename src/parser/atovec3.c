#include "../../inc/geometry.h"
#include "../../libs/libft/libft.h"

t_vec3	atovec3(char *input)
{
	char	**xyz;
	float	x;
	float	y;
	float	z;
	int		i;

	xyz = ft_split(input, ',');
	if (!xyz)
		ft_error(1, "parser", "atovec3/ft_split");
	i = 0;
	while (xyz[i])
		i++;
	if (i != 3)
		ft_error(1, "parser", "not vec3");
	x = ft_atof(xyz[0]);
	y = ft_atof(xyz[1]);
	z = ft_atof(xyz[2]);
	ft_free_darr(xyz);
	return ((t_vec3){x, y, z});
}
