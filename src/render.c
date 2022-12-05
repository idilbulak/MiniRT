#include "../inc/raytracer.h"
#include "../inc/miniRT.h"
#include <math.h>

// static int	convert_to_rgb(t_color pixelcolor)
// {
// 	return ((int)pixelcolor[0] << 24 | (int)pixelcolor[1] << 16
// | (int)pixelcolor[2] << 8 | 255);
// }

static void	clamp(float max, t_vec3 *color)
{
	(*color)[0] = fminf(max, (*color)[0]);
	(*color)[1] = fminf(max, (*color)[1]);
	(*color)[2] = fminf(max, (*color)[2]);
}

void	ft_render(mlx_image_t *img, t_scene *scene)
{	
	int		x;
	int		y;
	t_color	pixelcolor;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH - 1) //WITHOUT -1 HEAPBUFFER OVERFLOW???
		{
			cast_camera_ray(x, y, *scene, &pixelcolor);
			clamp(255, &pixelcolor);
			mlx_put_pixel(img, x, HEIGHT - y,
				(int)pixelcolor[0] << 24 |
				(int)pixelcolor[1] << 16 |
				(int)pixelcolor[2] << 8 | 255);
		}
	}
}
