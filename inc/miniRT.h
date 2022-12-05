#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/MLX42/include/MLX42/MLX42.h"

# define WIDTH  700
# define  HEIGHT 700

typedef struct s_scene	t_scene;

void	ft_render(mlx_image_t *img, t_scene *scene);

#endif