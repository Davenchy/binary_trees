CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89
NAME = a.out
SRC = $($(task)-main.c) $(wildcard $(task)-*.c)
SRC += $(foreach file, $(files), $(wildcard $(file)))
SRC += $(foreach file, $(extra), $(wildcard *-$(file).c))
OBJ = binary_tree_print.o $(SRC:.c=.o)

.PHONY: build run rerun clean fclean betty

$(NAME): $(OBJ)
ifeq ($(task),)
	$(error Please set the task number using `task=n`)
else
	$(CC) $(CFLAGS) -o $@ $^
endif

build: $(NAME)

run: $(NAME)
	@./$(NAME)

rerun: fclean run

betty:
	@if [ -z "$(TASK)" ]; then betty *.c *.h; else betty $(TASK)-*.c *.h; fi

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)
