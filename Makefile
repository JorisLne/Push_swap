NAME = push_swap
BONUS_NAME = checker

CC = gcc -g
RM = rm -fr
INC = -I ./includes/
FLAGS = -Wall -Wextra -Werror

SRC_FILES = ./srcs/utils/ft_split.c \
            ./srcs/utils/handle_errors.c \
            ./srcs/utils/initialize_stack.c \
            ./srcs/utils/sort_big_utils.c \
            ./srcs/utils/sort_big.c \
            ./srcs/utils/sort_three.c \
            ./srcs/utils/stack_utils.c \
            ./srcs/commands/push.c \
            ./srcs/commands/reverse_rotate.c \
            ./srcs/commands/rotate.c \
            ./srcs/commands/swap.c \
            ./push_swap.c

BONUS_FILES = ./srcs/checker/checker_utils.c \
              ./srcs/checker/checker.c \
              ./srcs/checker/get_next_line_utils.c \
              ./srcs/checker/get_next_line.c \
              ./srcs/utils/ft_split.c \
              ./srcs/utils/handle_errors.c \
              ./srcs/utils/initialize_stack.c \
              ./srcs/utils/sort_big_utils.c \
              ./srcs/utils/sort_big.c \
              ./srcs/utils/sort_three.c \
              ./srcs/utils/stack_utils.c \
              ./srcs/commands/push.c \
              ./srcs/commands/reverse_rotate.c \
              ./srcs/commands/rotate.c \
              ./srcs/commands/swap.c

OBJ_DIR = obj
OBJ = $(SRC_FILES:./%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(BONUS_FILES:./%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: ./%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(OBJ_BONUS)
	$(CC) $(FLAGS) $(INC) $(OBJ_BONUS) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

clean:
	$(RM) $(OBJ) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
