# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alexander <alexander@student.codam.nl>       +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/04 10:25:30 by alexander     #+#    #+#                  #
#    Updated: 2022/10/30 16:45:11 by ahorling      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

############### CONSTANTS ############

NAME := libft.a
CFLAGS := -Wall -Werror -Wextra
CC := gcc

############### SOURCES ##############

SOURCES	:= 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_numberleng.c \
		ft_hexalower.c \
		ft_hexaupper.c \
		ft_strcmp.c \
		ft_isnum.c \
		ft_whtspace.c \

OBJECT_DIR	:=	./objects
INCLUDE_DIR	:= 	./includes
PRINTF_DIR	:=	./printf/libftprintf.a
SOURCE_DIR	:=	./sources
OBJECTS 	:= 	$(addprefix $(OBJECT_DIR)/, $(SOURCES:.c=.o))

############### MESSAGES #############

START_MESSAGE	:=	"Making $(NAME)"
MESSAGE_FIN		:=	"libft library complete"
MESSAGE_RM		:=	"cleaned libft library"

############### WORKINGS #############


all: $(NAME)

$(PRINTF_DIR):
	@$(MAKE) -C printf/

$(NAME): $(PRINTF_DIR) $(OBJECTS)
	@ar rcs $@ $^
	@ar -q $(PRINTF_DIR) $(OBJECTS)
	@cp $(PRINTF_DIR) $(NAME)
	@echo $(MESSAGE_FIN)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)
	@$(MAKE) fclean -C printf/
	@echo $(MESSAGE_RM)

fclean: clean
	@rm -f $(NAME)
	@if [ -d "$(OBJECT_DIR)" ]; then rm -d $(OBJECT_DIR); fi

re: fclean all

.PHONY: clean fclean all re