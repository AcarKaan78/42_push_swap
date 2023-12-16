programname = push_swap
sources = main.c \
		input_check.c input_check_utils.c \
		initialization.c \
		stack.c \
		swap.c push.c rotate.c reverse_rotate.c \
		little_sort.c lazy_sort.c \
		position.c cost.c do_move.c \
		utils.c split.c input_check_utils2.c
objs = main.o \
		input_check.o input_check_utils.o \
		initialization.o \
		stack.o \
		swap.o push.o rotate.o reverse_rotate.o \
		little_sort.o lazy_sort.o \
		position.o cost.o do_move.o \
		utils.o split.o input_check_utils2.o

all: $(programname)

$(programname):
	gcc -Wall -Werror -Wextra $(sources) -o $(programname)

clean:
	rm -rf $(objs)

fclean: clean
	rm -rf $(programname)

re: fclean all