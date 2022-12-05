#include "../../inc/geometry.h"

t_vec3	normalize(t_vec3 v)
{
	float	len;
	float	inv_len;

	len = magnitude(v);
	if (len > 0)
	{
		inv_len = 1 / len;
		v[0] *= inv_len;
		v[1] *= inv_len;
		v[2] *= inv_len;
	}
	return (v);
}
