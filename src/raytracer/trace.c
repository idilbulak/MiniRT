#include "../../inc/raytracer.h"
#include <stdbool.h>
#include <math.h>

bool	trace(t_ray ray, t_object *objects, t_object **hitobj, float *tnear)
{
	float	t;

	t = INFINITY;
	while (objects)
	{
		if (objects->intersect(objects, ray, &t) && t < *tnear)
		{
			*tnear = t;
			*hitobj = objects;
		}
		objects = objects->next;
	}
	return (*hitobj != NULL);
}
