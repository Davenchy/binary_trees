CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89
NAME = a.out
SRC = $($(TASK)-main.c) $(wildcard $(TASK)-*.c)
OBJ = $(SRC:.c=.o)
EXTRA_FILES = $(foreach file, $(EXTRA), $(wildcard *-$(file).c))

.PHONY: build run rerun clean fclean betty

$(NAME): binary_tree_print.o $(OBJ)
	@if [ -z "$(TASK)" ]; then \
		echo "Please set the task number using \`TASK=n\`"; exit 1; fi
	$(CC) $(CFLAGS) -o $(NAME) $^ $(EXTRA_FILES)

build: $(NAME)

run: $(NAME)
	@./$(NAME)

rerun: fclean run

betty:
	@betty *.c *.h

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)
