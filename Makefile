# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 12:44:03 by thoberth          #+#    #+#              #
#    Updated: 2022/03/29 12:52:37 by thoberth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE = 		\033[0;34m
GREEN = 	\033[0;32m
LIGHTBLUE = \033[1;34m
RED = 		\033[0;31m
YELLOW = 	\033[1;33m
ORANGE = 	\033[0;33m
MAGENTA = 	\033[0;35m
RESET = 	\033[0m

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98

NAME = executable

NAME_STD = executable_std

SRCS = main.cpp

HDR =	containers/vector.hpp\
		containers/map.hpp\
		containers/stack.hpp\
		utils/bidirectional_iterator.hpp\
		utils/ft_utils.hpp\
		utils/iterator_traits.hpp\
		utils/iterator.hpp\
		utils/random_access_iterator.hpp\
		utils/red_black_tree.hpp\
		utils/reverse_iterator.hpp

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

main.o : ${HDR}

$(NAME): ${OBJS} ${HDR} ${SRCS}
	@printf "\n$(BLUE)"
	@printf "$(BLUE)Compiling files...\n"
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}
	@printf "$(GREEN)[$(NAME) done][✔]$(RESET)\n"
	@printf "\n"

std: ${fclean} ${HDR}
	${CXX} ${CXXFLAGS} -c -o main.o ${SRCS} -D USING_STD
	@printf "\n$(BLUE)"
	@printf "$(BLUE)Compiling files...\n"
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME_STD}
	@printf "$(GREEN)[$(NAME_STD) done][✔]$(RESET)\n"
	@printf "\n"

clean:
	@printf "\n"
	@printf "$(RED)Erase files '.o'\n"
	${RM} ${OBJS}
	@printf "$(RESET)\n"

fclean: clean
	@printf "\n"
	@printf "$(RED)Delete executable file\n"
	${RM} ${NAME}
	@printf "$(RESET)\n"

re: fclean all

.PHONY:	all clean fclean re
