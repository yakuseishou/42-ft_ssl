# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 11:56:33 by kchen2            #+#    #+#              #
#    Updated: 2019/10/25 23:17:59 by kchen2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

FUNCS = ft_atoi	\
		ft_bzero	\
		ft_isalnum	\
		ft_isalpha	\
		ft_isascii	\
		ft_isdigit	\
		ft_ispace	\
		ft_isprint	\
		ft_itoa	\
		ft_lstadd	\
		ft_lstdel	\
		ft_lstdelone	\
		ft_lstiter	\
		ft_lstmap	\
		ft_lstnew	\
		ft_memalloc	\
		ft_memccpy	\
		ft_memchr	\
		ft_memcmp	\
		ft_memcpy	\
		ft_memdel	\
		ft_memmove	\
		ft_memset	\
		ft_numlen	\
		ft_putchar	\
		ft_putchar_fd	\
		ft_putendl	\
		ft_putendl_fd	\
		ft_putnbr	\
		ft_putlong	\
		ft_putnbr_fd	\
		ft_putstr	\
		ft_putstr_fd	\
		ft_strcat	\
		ft_strchr	\
		ft_strclr	\
		ft_strcmp	\
		ft_strcpy	\
		ft_strdel	\
		ft_strdup	\
		ft_strequ	\
		ft_striter	\
		ft_striteri	\
		ft_strjoin	\
		ft_strlcat	\
		ft_strlen	\
		ft_strmap	\
		ft_strmapi	\
		ft_strncat	\
		ft_strndup	\
		ft_strncmp	\
		ft_strncpy	\
		ft_strnequ	\
		ft_strnew	\
		ft_strnstr	\
		ft_strrchr	\
		ft_strsplit	\
		ft_strstr	\
		ft_strsub	\
		ft_strtrim	\
		ft_tolower	\
		ft_toupper	\
		ft_word_count	\
		ft_word_len		\
		ft_puterror		\
		itoa_base	\
		get_next_line \
		ft_printf \
		print_int \
		ulti_di	\
		store_flags \
		check_data \
		prin_num \
		prin_num_zpad \
		prin_f \
		ulti_f \
		prin_lf \
		ulti_lf \
		ulti_fex
		
SRC = $(addprefix srcs/, $(addsuffix .c, $(FUNCS)))

OBJ = $(addsuffix .o, $(FUNCS))

all: $(NAME) 

$(NAME): $(OBJ)
	@echo "	Making .a file"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "	libft.a was made"

$(OBJ):
	@echo "	Making .o files"
	@gcc $(FLAGS) -c $(SRC)
	@echo "	$(words $(OBJ)) obj was made"

clean:
	@/bin/rm -f $(OBJ)
	@echo "	$(words $(OBJ)) obj deleted"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "	libft.a deleted"

re: fclean all

s: clean
