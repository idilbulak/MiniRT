#include "../../libs/libft/libft.h"
#include "../../inc/parser.h"
#include "../../inc/geometry.h"
#include <fcntl.h>

static bool	check_argc(char **line, int count, char *str)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i != count)
		ft_error(1, "parser: invalid number of arguments", str);
	return (true);
}

static void	parse_rtfile(char **input, t_scene *scene)
{
	static int	ambient = 0;
	static int	camera = 0;
	static int	light = 0;

	if (!ft_strcmp(input[0], "A") && check_argc(input, 3, "A")
		&& ++ambient <= 1)
		parse_ambient(input, scene);
	else if (!ft_strcmp(input[0], "C") && check_argc(input, 4, "C")
		&& ++camera <= 1)
		parse_camera(input, scene);
	else if (!ft_strcmp(input[0], "L") && check_argc(input, 4, "L")
		&& ++light <= 1)
		parse_light(input, scene);
	else if (!ft_strcmp(input[0], "sp") && check_argc(input, 4, "sp"))
		parse_sphere(input, scene);
	else if (!ft_strcmp(input[0], "pl") && check_argc(input, 4, "pl"))
		parse_plane(input, scene);
	else if (!ft_strcmp(input[0], "cy") && check_argc(input, 6, "cy"))
		parse_cylinder(input, scene);
	else if (ft_strcmp(input[0], "\n"))
		ft_error(1, "parser: invalid file input at", input[0]);
}

static void	check_extension(char *argv)
{
	while (*argv && *argv != '.')
		argv++;
	if (ft_strcmp(argv + 1, "rt"))
		ft_error(1, "parser", "invalid file extension");
}

void	parser(char *argv, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**input;

	scene->objects = NULL;
	scene->light = NULL;
	check_extension(argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error(1, "parser", "couldn't open the file");
	line = get_next_line(fd);
	while (line)
	{
		input = ft_split(line, ' ');
		if (!input)
			ft_error(1, "parser", "invalid input");
		parse_rtfile(input, scene);
		ft_free_darr(input);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
