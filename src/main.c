/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 11:54:48 by ibulak        #+#    #+#                 */
/*   Updated: 2022/11/11 12:25:16 by daansaat      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include "../inc/parser.h"
#include "../libs/libft/libft.h"

static void	_mlx_keypress(keys_t key)
{
	if (key == MLX_KEY_ESCAPE)
		exit(EXIT_SUCCESS);
}

static void	init_mlx42(mlx_t **mlx, mlx_image_t **img)
{
	*mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	if (!*mlx)
		exit(EXIT_FAILURE);
	*img = mlx_new_image(*mlx, WIDTH, HEIGHT);
	if (!*img)
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_scene		scene;

	if (argc != 2)
		ft_error(1, "parser", "wrong number of arguments");
	init_mlx42(&mlx, &img);
	parser(argv[1], &scene);
	ft_render(img, &scene);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, (mlx_keyfunc)_mlx_keypress, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
