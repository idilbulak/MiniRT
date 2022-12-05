#ifndef PARSER_H
# define PARSER_H

# include "scene_structs.h"

void	parser(char *argv, t_scene *scene);

void	parse_ambient(char **line, t_scene *scene);
void	parse_light(char **line, t_scene *scene);
void	parse_camera(char **line, t_scene *scene);

void	parse_sphere(char **line, t_scene *scene);
void	parse_plane(char **line, t_scene *scene);
void	parse_cylinder(char **line, t_scene *scene);
void	parse_cone(char **line, t_scene *scene);

t_vec3	atovec3(char *input);
t_vec3	check_vec3(float min, float max, t_vec3 input, char *str);

#endif