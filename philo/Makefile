_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

_DEFAULT=\033[39m
_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_MAGENTA=\033[35m
_CYAN=\033[36m
_LIGHTGRAY=\033[37m
_DARKGRAY=\033[90m
_LIGHTRED=\033[91m
_LIGHTGREEN=\033[92m
_LIGHTYELLOW=\033[93m
_LIGHTBLUE=\033[94m
_LIGHTMAGENTA=\033[95m
_LIGHTCYAN=\033[96m
_WHITE=\033[97m

NAME = philo

CC = clang
MAKE = make --no-print-directory

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -O3 -fno-builtin
# CFLAGS += -g
# CFLAGS += -fsanitize=address

CLIBS = -lpthread

HEADERS = \
	./includes/philo.h

PHILO_LIB = \
	./lib/checks.c \
	./lib/len.c \
	./lib/memory.c \
	./lib/nb_convert.c \
	./lib/print.c \

PHILO_SRC = \
	./src/close.c \
	./src/init.c \
	./src/main.c \
	./src/philo_die.c \
	./src/philo_init.c \
	./src/philo_tasks.c \
	./src/print.c \
	./src/time.c \

SRCS = \
	$(PHILO_LIB) \
	$(PHILO_SRC) \

OBJS = $(SRCS:%.c=%.o)

%.o: %.c $(HEADERS) Makefile
	@printf "[ $(_GREEN)$(_BOLD)compiling$(_END) ] $(_BLUE)$(_BOLD)$<$(_END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@printf "[ $(_YELLOW)$(_BOLD)building$(_END) ] $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"
	@$(CC) $(CFLAGS) $(CLIBS) -o $(NAME) $(OBJS)
	@printf "[ $(_MAGENTA)$(_BOLD)done$(_END) ]\n"

clean:
	@printf "[ $(_RED)$(_BOLD)removing$(_END) ] $(_BLUE)$(_BOLD)objs$(_END)\n"
	@$(RM) $(OBJS)

fclean: clean
	@printf "[ $(_RED)$(_BOLD)removing$(_END) ] $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"
	@$(RM) $(NAME)

re: fclean
	@$(MAKE) all

norm:
	@norminette

.PHONY: all clean fclean re norm
