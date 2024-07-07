CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

SRCS = pushswap.c main.c check.c push.c split.c store.c rx.c \
    rrx.c px.c sx.c upre.c utils.c utils2.c min_cmds.c get_cmds.c\

SRCS_BONUS = checker.c pushswap.c check.c push.c split.c store.c rx.c \
    rrx.c px.c sx.c upre.c utils.c utils2.c min_cmds.c get_cmds.c\
    get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(DEPS)
	$(CC) $(OBJS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(DEPS) 
	$(CC) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
