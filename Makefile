############## COLOUR CODES ##########

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

############## CONSTANTS #############

NAME1 := server
NAME2 := client
CC := gcc
CFLAGS := -Wall -Wextra -Werror

############### SOURCES ##############

SOURCES1 	:=	server.c\
				
SOURCES2	:=	client.c\

LIBRARIES	:=	./libraries/libft/libft.a\
				
HEADERS		:=	-I ./includes -I $(LIBFT)/includes			
SOURCE_DIR1	:=	./sources/server/
SOURCE_DIR2	:=	./sources/client/
INCLUDE_DIR	:= 	./includes
OBJECT_DIR	:=	./objects
OBJECT_DIR1	:=	./objects/server
OBJECT_DIR2	:=	./objects/client
LIBFT		:=	./libraries/libft
OBJECTS1 	:= 	$(addprefix $(OBJECT_DIR1)/, $(SOURCES1:.c=.o))
OBJECTS2 	:= 	$(addprefix $(OBJECT_DIR2)/, $(SOURCES2:.c=.o))

############### MESSAGES ########

MESSAGE		:=	"Making $(NAME)"
SERVER_FIN	:=	"SERVER COMPLETE, NO ERRORS"
CLIENT_FIN	:=	"CLIENT COMPLETE, NO ERRORS"
MESSAGE_RM	:=	"OBJECTS CLEANED"
MESSAGE_FRM	:=	"EVERYTHING CLEANED"
MESSAGE_LIB	:=	"LIBRARIES READY"

############### RUNNING ##############

all: libraries $(NAME1) $(NAME2)

$(NAME1): $(OBJECTS1)
	@$(CC) $(CFLAGS) $(LIBRARIES) -o $@ $^ $(HEADERS)
	@echo "$(GREEN)$(BOLD)$(SERVER_FIN)$(RESET)"

$(NAME2): $(OBJECTS2)
	@$(CC) $(CFLAGS) $(LIBRARIES) -o $@ $^ $(HEADERS)
	@echo "$(GREEN)$(BOLD)$(CLIENT_FIN)$(RESET)"

$(OBJECT_DIR1)/%.o: $(SOURCE_DIR1)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< -O3

$(OBJECT_DIR2)/%.o: $(SOURCE_DIR2)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< -O3

run:
	make && ./$(NAME)

clean:
	@rm -f $(OBJECTS1) $(OBJECTS2)
	@$(MAKE) fclean -C $(LIBFT)
	@echo "$(RED)$(MESSAGE_RM)$(RESET)"

fclean: clean
	@rm -f $(NAME1) $(NAME2)
	@if [ -d "$(OBJECT_DIR)" ]; then rm -drf $(OBJECT_DIR); fi
	@echo "$(RED)$(MESSAGE_FRM)$(RESET)"

libraries:
	@$(MAKE) -s -C $(LIBFT)
	@echo "$(GREEN)$(MESSAGE_LIB)$(RESET)"

re: fclean all

.PHONY: all clean fclean re libraries
