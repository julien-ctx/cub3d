GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

NAME = cub3D

PROJECT = CUB3D_BONUS

C_DIR = ../common

SRCS = main.c \
		$(addprefix ./srcs/parsing/, parsing.c param_error.c utils.c map_error.c check_directions.c) \
		$(addprefix ./srcs/raycasting/, raycasting.c init_data.c drawing.c moves.c ray_data.c keys.c mouse.c map.c) \
		$(addprefix $(C_DIR)/gnl/, get_next_line.c get_next_line_utils.c)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADER = -I./includes -I./$(C_DIR)/libft -I./$(C_DIR)/gnl -I./$(C_DIR)/minilibx

all: $(NAME)

bonus: $(OBJS) 
	@make WITH_BONUS=1 all

.c.o: $(SRCS)
	@gcc $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@make -C $(C_DIR)/minilibx 2>/dev/null
	@make bonus -C $(C_DIR)/libft/
	@gcc $(CFLAGS) $(HEADER) -o $(NAME) $(SRCS) -lm -L $(C_DIR)/libft -lft -lmlx -framework OpenGL -framework AppKit -L $(C_DIR)/gnl -L $(C_DIR)/minilibx
	@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(NAME)$(GREEN)" has been created\n"$(RESET)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(C_DIR)/gnl/get_next_line.o
	@rm -rf $(C_DIR)/gnl/get_next_line_utils.o
	@make clean -C $(C_DIR)/libft
	@make clean -C $(C_DIR)/minilibx
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)

fclean:
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@rm -rf $(C_DIR)/gnl/get_next_line.o
	@rm -rf $(C_DIR)/gnl/get_next_line_utils.o
	@rm -rf $(C_DIR)/libft/libft.a
	@make fclean -C $(C_DIR)/libft
	@make clean -C $(C_DIR)/minilibx
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"fclean"$(RED)" has been done\n"$(RESET)

amongus: all
	@./cub3D ../maps/amongus.cub

bocal: all
	@./cub3D ../maps/bocal.cub

clusters: all
	@./cub3D ../maps/clusters.cub

futuristic: all
	@./cub3D ../maps/futuristic.cub

jungle: all
	@./cub3D ../maps/jungle.cub

mine: all
	@./cub3D ../maps/mine.cub

village: all
	@./cub3D ../maps/village.cub

library: all
	@./cub3D ../maps/library.cub

re: fclean all

.PHONY: all clean fclean re amongus bocal clusters futuristic jungle mine village library
