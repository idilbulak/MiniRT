#include "../../inc/geometry.h"
#include <math.h>

//coef:coefficients
//r:root

float	quadratic(float coef[3])
{
	float	discriminant;
	float	r1;
	float	r2;

	discriminant = coef[1] * coef[1] - 4.0 * coef[0] * coef[2];
	if (discriminant < 0)
		return (0);
	r1 = (-coef[1] + sqrtf(discriminant)) / (2 * coef[0]);
	r2 = (-coef[1] - sqrtf(discriminant)) / (2 * coef[0]);
	return (findmin(r1, r2));
}
