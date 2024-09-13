# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:33:13 by dparada           #+#    #+#              #
#    Updated: 2024/09/13 12:45:17 by malena-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
USER = malena-b
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src/
OBJ_DIR = obj/
B_SRC_DIR = Bonus/

DEF_COLOR	= \033[0;39m
MAGENTA		= \033[0;35m
YELLOW		= \033[0;33m
GREEN		= \033[0;32m
WHITE		= \033[0;37m
RESET		= \033[0m
GRAY		= \033[0;90m
BLUE		= \033[0;34m
CYAN		= \033[0;37m
RED			= \033[0;31m
BOLD		= \033[1m

SRC_FILES = 
BONUS_FILES =

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BONUS_SRC = $(addprefix $(B_SRC_DIR), $(addsuffix .c, $(BONUS_FILES)))
BONUS_OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME):	compiling	$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)COMPLETE!$(RESET)"
	@echo

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(MAGENTA)COMPILING...		$(BLUE)$(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(B_SRC_DIR)%.c | $(OBJF)
	@echo "$(MAGENTA)COMPILING...		$(BLUE)$(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

compiling:
	@echo "$(YELLOW)COMPILING PHILOSOPHERS FILES:$(RESET)"

clean:
	@rm -frf $(OBJ_DIR)

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)
	@echo "$(YELLOW)Philosophers fclean:	 	$(GREEN)[COMPLETED]$(EC)"
	@echo

re: fclean all
	@echo "$(YELLOW)PHILOSOPHERS: $(GREEN)[RECOMPILED]$(RESET)"

norm:
	@echo "Norminette of Philosophers files: "
	@norminette $(SRC_DIR)
	@norminette $(B_SRC_DIR)
	@echo

bonus: $(BONUS_OBJ)
			@$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)
			@echo "$(GREEN)BONUS COMPLETE!$(RESET)"
			@echo
.PHONY: all clean fclean re norm compiling bonus

