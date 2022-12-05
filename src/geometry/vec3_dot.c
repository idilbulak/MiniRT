#include "../../inc/geometry.h"

float	dot(t_vec3 u, t_vec3 v)
{
	return (u[0] * v[0] + u[1] * v[1] + u[2] * v[2]);
}
