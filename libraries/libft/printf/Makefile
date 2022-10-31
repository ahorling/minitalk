# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ahorling <ahorling@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/07/20 16:42:04 by ahorling      #+#    #+#                  #
#    Updated: 2022/08/23 17:34:13 by ahorling      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

############## CONSTANTS #############

NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror

############### SOURCES ##############

SOURCES 	:=	ft_printf.c \
				print_pointer.c \
				print_char.c \
				print_hexa_lower.c \
				print_hexa_upper.c \
				print_int.c \
				print_percent.c \
				print_string.c \
				print_unsigned.c \
				libft_functions1.c \
				libft_functions2.c \

LIB_DIR		:=	../libft/libft.a
SOURCE_DIR 	:=	./sources
INCLUDE_DIR	:= 	./includes
OBJECT_DIR	:=	./objects
OBJECTS 	:= 	$(addprefix $(OBJECT_DIR)/, $(SOURCES:.c=.o))

############### MESSAGES ########

MESSAGE		:=	"Making $(NAME)"
MESSAGE_FIN	:=	"printf complete"
MESSAGE_RM	:=	"printf cleaned"

############### RUNNING ##############

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $@ $^
	@echo $(MESSAGE_FIN)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)
	@echo $(MESSAGE_RM)

fclean: clean
	@rm -f $(NAME)
	@if [ -d "$(OBJECT_DIR)" ]; then rm -d $(OBJECT_DIR); fi

re: fclean all

.PHONEY: all clean fclean re
