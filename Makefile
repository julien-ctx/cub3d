GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

NAME = cub3d

PROJECT = CUB3D

SRCS = main.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADER = -I./includes -I./srcs/libft -I./srcs/gnl -I./srcs/minilibx

all: $(NAME)

.c.o: $(SRCS)
	@gcc $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@make -C srcs/minilibx 2>/dev/null
	@make bonus -C srcs/libft/
	@gcc $(CFLAGS) $(HEADER) -o $(NAME) $(SRCS) -Ofast -L srcs/libft -lft -lmlx -framework OpenGL -framework AppKit -L srcs/gnl -L srcs/minilibx
	@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(NAME)$(GREEN)" has been created\n"$(RESET)

clean:
	@rm -rf $(OBJS) 
	@make clean -C includes/libft
	@make clean -C includes/minilibx
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)

fclean:
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@rm -rf includes/libft/libft.a
	@make fclean -C srcs/libft
	@make clean -C srcs/minilibx
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"fclean"$(RED)" has been done\n"$(RESET)

re: fclean all

.PHONY: all clean fclean re
