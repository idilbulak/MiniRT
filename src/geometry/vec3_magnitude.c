#include "../../inc/geometry.h"
#include <math.h>

float	magnitude(t_vec3 v)
{
	return (sqrtf(dot(v, v)));
}
