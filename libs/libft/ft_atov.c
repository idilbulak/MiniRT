#include "libft.h"
#include <math.h>

void	setv(t_vec3 *vec, float x, float y, float z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_vec3    ft_atov3(char *str, t_vec3 vec)
{
	char	**point;
	int		i = 0;
	float	x = 0;
	float	y = 0;
	float	z = 0;

	point = ft_split(str, ',');
    if (!point)
		ft_error(1, "parser", "atov/ft_split");
	while (point[i])
		i++;
	if (i != 3)
		ft_error(1, "parser", "not vec3");
	x = ft_atof(point[0]);
	y = ft_atof(point[1]);
	z = ft_atof(point[2]);
	setv(&vec, x, y, z);
    while (i > 0)
    {
        free (point[i-1]);
        i--;
    }
	free (point);
	return (vec);
}