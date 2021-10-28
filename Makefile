# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 19:47:29 by vifernan          #+#    #+#              #
#    Updated: 2021/10/28 17:44:49 by vifernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address
LINK	= -lmlx -framework OpenGL -framework AppKit
SRCS	= 	drw.c \
			read.c \
			color.c \
			get_next_line.c \
			ajust.c \
			isometric.c \
			hook.c \
			help.c \
			free.c \
			get_color.c \
			sizes.c \
			fill_maps.c \
			mini_printf.c \

OBJS	= $(SRCS:.c=.o)
CC		= 	gcc
INCLUDES = -I./includes

all: $(NAME)

BCyan = \033[1;36m
GREEN = \033[0;32m
Yellow = \033[0;33m
Red = \033[0;31m
NO_COLOR = \033[0m

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) libft/libft.a $(OBJS) $(LINK) -o $(NAME)
	@echo "$(GREEN)[COMPILED]$(NO_COLOR)"

clean:
	rm -rf $(OBJS)
	@$(MAKE) fclean -C ./libft
	@echo "$(Yellow)[CLEAN]$(NO_COLOR)"

fclean: clean
	rm -rf $(NAME)
	@echo "$(Red)[FCLEAN]$(NO_COLOR)"
	
re: fclean all

test: all
	@echo "$(GREEN)------------------------------------------[MAPS]------------------------------------------$(NO_COLOR)"
	@ls ./test_maps_3 | cut -d "." -f 1 | column -c 100
	@echo "$(GREEN)------------------------------------------------------------------------------------------$(NO_COLOR)"
	@echo "$(Red)[Reading map..]$(NO_COLOR)"
	@read -p "Select map name: " map; \
	./fdf ./test_maps_3/$${map}.fdf

.PHONY: all clean fclean re bonus test
