# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 23:32:08 by ymafaman          #+#    #+#              #
#    Updated: 2024/02/14 20:12:27 by ymafaman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

CFILES = main.c Errors/errors.c Errors/errors2.c game_play/changing_images.c game_play/enemy_movements.c game_play/init_helpers.c game_play/key_release.c game_play/map_setting.c \
game_play/map_setting2.c game_play/move_enems.c game_play/player_moving.c memory_freeing/memory_freeing.c  \
mlx_thingz/final_game_play.c parsing/boundaries_checking.c parsing/map_validity_check.c parsing/map_validity_check_2.c parsing/valid_path_checking.c parsing/valid_path_checking_2.c \
reading_from_file/get_next_line.c reading_from_file/get_next_line_utils.c str_functions/str_functions1.c str_functions/str_functions2.c mlx_thingz/images_setting.c mlx_thingz/images_setting2.c

OFILES = $(CFILES:.c=.o)

NAME = so_long

all : $(NAME)

$(NAME) : $(OFILES)
		$(CC) $(FLAGS) $(OFILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean re fclean 