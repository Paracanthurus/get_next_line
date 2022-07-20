# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 07:41:16 by aokubo            #+#    #+#              #
#    Updated: 2022/07/21 07:44:47 by aokubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= libgnl.a
SRCS	= get_next_line.c get_next_line_utils.c
B_SRCS	= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)
ifdef BONUS
 OBJS += $(B_OBJS)
endif
CC		= gcc
AR		= ar rcs
CFLAGS	= -Wall -Wextra -Werror

$(NAME):	$(OBJS)
			$(AR) $(NAME) $^

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $<

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:
			make BONUS=1

.PHONY:		all clean fclean re bonus
