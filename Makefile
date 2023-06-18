NAME 		= client server
CFLAGS 		= -Wall -Wextra -Werror
SRCDIR		= ./src
CLIENTDIR	= $(SRCDIR)/client
SERVERDIR	= $(SRCDIR)/server
SRC_CLIENT 	= $(wildcard $(CLIENTDIR)/*.c)
SRC_SERVER 	= $(wildcard $(SERVERDIR)/*.c)
INCLUDES	= -I ./includes

all: $(NAME)

$(NAME): $(SRC_CLIENT) $(SRC_SERVER)
	if [ $@ = "client" ]; then \
		$(CC) -o $@ $(CFLAGS) $(SRC_CLIENT) $(INCLUDES); \
	else \
		$(CC) -o $@ $(CFLAGS) $(SRC_SERVER) $(INCLUDES); \
	fi

norm:
	norminette -R CheckForbiddenSourceHeader

re: fclean all

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re