# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 00:01:46 by klemongr          #+#    #+#              #
#    Updated: 2022/03/31 22:53:21 by klemongr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Wextra -Werror

HEADER = philo.h

LIST = 	main.c				\
		for_struct.c		\
		philosopher.c		\
		char_to_smth.c		\
		monitoring.c		\
		create_threads.c	\

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
