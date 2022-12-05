#include "../../inc/geometry.h"

t_vec3	cross(t_vec3 u, t_vec3 v)
{
	t_vec3	cross_product;

	cross_product[0] = u[1] * v[2] - u[2] * v[1];
	cross_product[1] = u[2] * v[0] - u[0] * v[2];
	cross_product[2] = u[0] * v[1] - u[1] * v[0];
	return (cross_product);
}
