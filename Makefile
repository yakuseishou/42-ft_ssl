# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 15:40:53 by kchen2            #+#    #+#              #
#    Updated: 2019/11/01 16:30:53 by kchen2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

FLAGS = -Wall -Werror -Wextra

INCS = includes
LIB = libft/libft.a

FILES = ft_ssl \
		flags \
		prin_file \
		prin_in \
		dis_table \
		mdf \
		mdf_ulti \
		sha_tfs \
		sha_tfs_ulit \
		sha_tfs_prin

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(LIB)
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
	
$(LIB):
	@make -C libft/

clean:
	@rm -f $(OBJS)
	@make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norm:
	norminette $(SRCS) *.h