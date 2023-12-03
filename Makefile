##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME		:=   my_hunter
CC			:=   gcc

INC_DIR		:=   ./include/
SRC_DIR		:=   ./src/
OBJ_DIR		:=   ./obj/

CFLAGS		+=  -Wall -Wextra -Werror
CPPFLAGS	:=  -iquote $(INC_DIR)
LDLIBS		:=  -lcsfml-audio -lcsfml-graphics -lcsfml-network -lcsfml-system -lcsfml-window
DEBUG		?=  -g3

SRCS		:=   $(shell find $(SRC_DIR) -name '*.c')
OBJS		:=   $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

debug: CFLAGS += $(DEBUG)
debug: all

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
