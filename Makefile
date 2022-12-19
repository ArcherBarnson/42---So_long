# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 15:32:18 by bgrulois          #+#    #+#              #
#    Updated: 2022/08/31 14:55:01 by bgrulois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long	

NAME_B 	=	so_long

SRCS	=	libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_itoa.c \
		libft/ft_split.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		srcs/err_codes.c \
		srcs/struct_init.c \
		srcs/memory_handler.c \
		srcs/parsing_utils.c \
		srcs/parsing.c \
		srcs/map_tools_utils.c \
		srcs/map_tools.c \
		srcs/rules.c \
		srcs/events.c \
		srcs/sprites.c \
		srcs/display.c \
		main.c

SRCS_B	=	libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_itoa.c \
		libft/ft_split.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		srcs/err_codes.c \
		srcs/struct_init.c \
		bonus/memory_handler.c \
		srcs/parsing_utils.c \
		srcs/parsing.c \
		bonus/map_tools_utils.c \
		bonus/map_tools.c \
		bonus/ennemies.c \
		bonus/rules.c \
		bonus/events.c \
		bonus/sprites.c \
		bonus/display.c \
		bonus/main.c

CC	=	gcc	

CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	${SRCS:%.c=%.o}

OBJS_B	=	${SRCS_B:%.c=%.o}

all: 		${NAME}

%.o:		%.c
		$(CC) $(CFLAGS) -I /usr/include -I mlx_linux -c $< -o $@

${NAME}: 	$(OBJS)
		make -C mlx_linux 
		${CC} ${CFLAGS} $(OBJS) -L mlx_linux -lmlx -L /usr/lib -I mlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus: 	$(OBJS_B)
		make -C mlx_linux 
		${CC} ${CFLAGS} $(OBJS_B) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


clean:		
		make clean -C mlx_linux
		rm -rf ${OBJS}

clean_b:	
		rm -rf ${OBJS_B}

fclean:		clean
		rm -rf ${NAME}

fclean_b:	clean_b
		rm -rf ${NAME_B}

re:		fclean 
		make

.PHONY:		all clean fclean re bonus
