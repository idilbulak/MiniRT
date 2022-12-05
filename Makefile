NAME = miniRT
GCC	= gcc
INC = -Iinc -Ilibs/libft 
# FLAGS = -Wall -Werror -Wextra
# FLAGS = -fsanitize=address
MLX42 = libs/MLX42/libmlx42.a
LIBFT = libs/libft/libft.a
# GLFW_LIB = -L /Users/$(USER)/.brew/opt/glfw/lib/ # CODAM
# GLFW_LIB = -L /opt/homebrew/Cellar/glfw/3.3.6/lib # pro
GLFW_LIB = -L /opt/homebrew/Cellar/glfw/3.3.8/lib # iMac

HEADERS = 	\
		inc/miniRT.h \
		inc/geometry.h \
		inc/parser.h \
		inc/raytracer.h \
		inc/scene_structs.h \
		inc/shape_structs.h

SRCS =	main.c \
		parser/parser.c \
		parser/atovec3.c \
		parser/check_vec3.c \
		parser/parse_ambient.c \
		parser/parse_camera.c \
		parser/parse_light.c \
		parser/parse_shapes.c \
		render.c \
		raytracer/cast_camera_ray.c \
		raytracer/cast_shadow_ray.c \
		raytracer/trace.c \
		geometry/intersect_sphere.c \
		geometry/intersect_plane.c \
		geometry/intersect_cylinder.c \
		geometry/intersect_cone.c \
		geometry/get_surface_normal.c \
		geometry/findmin.c \
		geometry/point_at.c \
		geometry/quadratic.c \
		geometry/vec3_cross.c \
		geometry/vec3_dot.c \
		geometry/vec3_magnitude.c \
		geometry/vec3_normalize.c

SRCS_BNS =	main.c \
		parser/parser_bonus.c \
		parser/atovec3.c \
		parser/check_vec3.c \
		parser/parse_ambient.c \
		parser/parse_camera.c \
		parser/parse_light.c \
		parser/parse_shapes.c \
		render.c \
		raytracer/cast_camera_ray.c \
		raytracer/cast_shadow_ray.c \
		raytracer/trace.c \
		geometry/intersect_sphere.c \
		geometry/intersect_plane.c \
		geometry/intersect_cylinder.c \
		geometry/intersect_cone.c \
		geometry/get_surface_normal.c \
		geometry/findmin.c \
		geometry/point_at.c \
		geometry/quadratic.c \
		geometry/vec3_cross.c \
		geometry/vec3_dot.c \
		geometry/vec3_magnitude.c \
		geometry/vec3_normalize.c

SRCS_DIR = src/
SRCS_BNS_DIR = src/
OBJS_DIR = obj/
SUB_DIR = parser,geometry,raytracer
OBJS = 
ifdef WITH_BONUS
OBJS = $(SRCS_BNS:%.c=$(OBJS_DIR)%.o) $(BONUS:.c=.o)
else
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)
endif
######################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX42) $(HEADERS)
	@$(GCC) $(FLAGS) $(LIBFT) $(MLX42) $(OBJS) $(GLFW_LIB) -lglfw -o $(NAME) 
	@echo "\033[0;36mCompiling miniRT..."

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS)
	@printf "\033[0;33mGenerating miniRT objects... %-33.33s\r" $@
	@mkdir -p $(OBJS_DIR){$(SUB_DIR)}
	@$(GCC) $(FLAGS) $(INC) -c $< -o $@

$(LIBFT):
	@printf "\n"
	@$(MAKE) -C libs/libft
	@printf "\033[0m"

$(MLX42):
	@$(MAKE) -C libs/MLX42

bonus:
	@$(MAKE) WITH_BONUS=1
clean:
	@$(MAKE) -C libs/libft clean
	@$(MAKE) -C libs/MLX42 clean
	@rm -rdf $(OBJS_DIR)
	@echo "\033[0;31mObjects deleted!"
	@printf "\033[0m"

fclean: clean
	@echo "\033[0;31mExecutable deleted!"
	@rm -f $(NAME)
	@rm -f $(MLX42)
	@rm -f $(LIBFT)
	@printf "\033[0m"

re: fclean all
