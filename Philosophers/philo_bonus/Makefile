# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 00:01:46 by klemongr          #+#    #+#              #
#    Updated: 2022/04/06 16:18:24 by klemongr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

FLAGS = -Wall -Wextra -Werror

HEADER = philo.h

LIST = 	main.c			\
		create_var.c	\
		create_pid.c	\
		time.c			\
		char_to_smth.c	\
		philosopher.c	\

OBJSFD = temporary

OBJ = $(addprefix $(OBJSFD)/,$(LIST:.c=.o))

all : $(NAME)

$(OBJSFD) :
	mkdir $@

$(OBJSFD)/%.o : %.c $(HEADER) | $(OBJSFD)
	cc -g $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
	cc -g $(OBJ) -o $@

clean :
	rm -f $(OBJ)

fclean : clean

re : fclean all

.PHONY : all clean fclean re
