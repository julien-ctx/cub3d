SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memset.c \
	   ft_split.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strlen.c \
	   ft_strnstr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_strrchr.c \
	   ft_strjoin.c \
	   ft_substr.c \
	   ft_isalpha.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strncmp.c \
	   ft_memcmp.c \
	   ft_memchr.c \
	   ft_calloc.c \
	   ft_strlcat.c \
	   ft_strtrim.c \
	   ft_itoa.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_strmapi.c \
	   ft_striteri.c \


B_SRCS = $(SRCS) \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

ifdef WITH_BONUS
	OBJS = $(B_SRCS:.c=.o)
else
	OBJS = $(SRCS:.c=.o)
endif

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

bonus: $(OBJS)
	@make WITH_BONUS=1 all

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	@make WITH_BONUS=1 s_clean

fclean: clean
	@make WITH_BONUS=1 s_fclean

s_clean:
	rm -rf $(OBJS)

s_fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
