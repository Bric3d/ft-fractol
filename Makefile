# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/08 15:08:34 by bbecker           #+#    #+#              #
#    Updated: 2015/02/12 16:18:17 by bbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

F = ./srcs/

I = -I./headers

L = -L./lib -lft -L /usr/X11/lib -lmlx -lXext -lX11

TOMAKE =	$(F)main.c					\
			$(F)color.c					\
			$(F)tools.c					\
			$(F)random.c				\
			$(F)fractals.c				\
			$(F)fractals2.c				\
			$(F)mouse_hook.c			\
			$(F)error.c


TOLIB	=	main.o						\
			error.o						\
			fractals.o					\
			fractals2.o					\
			tools.o						\
			random.o					\
			mouse_hook.o				\
			color.o

all: $(NAME)

$(NAME):
	@echo "Getting libraries..."
	@make -C ./lib/libft
	@echo "Done."
	@echo "Compiling project..."
	@gcc -c -Wall -Werror -Wextra $(TOMAKE) $(I) $(L)
	@gcc -Wall -Werror -Wextra $(I) $(L) -o $(NAME) $(TOLIB)
	@echo "All set.\n"

test:
	@make -C ./lib/libft test
	@cp ../libft.a ./lib/
	@echo "Compiling project with debug flags..."
	@gcc -c -g -Wall -Werror -Wextra $(TOMAKE) $(I) $(L)
	@gcc -g -Wall -Werror -Wextra $(I) $(L) -o $(NAME) $(TOLIB)
	@echo "All set."

clean :
	@/bin/rm -rf $(TOLIB)
	@echo "Cleaned"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f ./lib/libft.a
	@echo "All filed deleted"

re: fclean all

help:
	@echo "--------------------\n\n\
	Compile with all\nUsage : ./fractol X Y\n\
	Max X = 2560\nMax Y = 1350\n\
	\n--------------------\n\n\
	Zoom with |+| and |-|\n\
	Toogle smoothing with |page up|, |page down| and |P|\nR G and B can be\
	 choosed with the pad\nChoose the fractals with |1| to |9|\n\
	Toogle precise tuning of values with |home| and |end|\n\
	Turn mouse on and off with |m|\n\
	Generate a random color with |space|\n\
	 \n--------------------"

.PHONY: fclean clean all test helpc
