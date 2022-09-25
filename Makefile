NAME = cub3D

NAME_BONUS = cub3D_bonus

all: $(NAME)
	@mv mandatory/cub3D .

bonus: $(NAME_BONUS)
	@mv bonus/cub3D .

$(NAME):
	@make -C mandatory

$(NAME_BONUS):
	@make -C bonus

clean:
	@make clean -C mandatory
	@make clean -C bonus

fclean:
	@make fclean -C mandatory
	@make fclean -C bonus
	@rm -rf cub3D

amongus:
	@./cub3D maps/amongus.cub

bocal:
	@./cub3D maps/bocal.cub

clusters:
	@./cub3D maps/clusters.cub

futuristic:
	@./cub3D maps/futuristic.cub

jungle:
	@./cub3D maps/jungle.cub

mine:
	@./cub3D maps/mine.cub

village:
	@./cub3D maps/village.cub

library:
	@./cub3D maps/library.cub

re: fclean all

.PHONY: all clean fclean re bonus amongus bocal clusters futuristic jungle mine village library
