NAME 		= client server
CFLAGS 		= -Wall -Wextra -Werror $(LFLAGS)
DFLAGS 		= $(CFLAGS) -g -fsanitize=address,undefined
LFLAGS		= -L./ -lft -lftprintf 
SRCDIR		= ./src
LIBDIR		= $(SRCDIR)/libs
CLIENTDIR	= $(SRCDIR)/client
SERVERDIR	= $(SRCDIR)/server
SRC_CLIENT 	= $(wildcard $(CLIENTDIR)/*.c)
SRC_SERVER 	= $(wildcard $(SERVERDIR)/*.c)
INCLUDEDIR	= ./includes $(LIBDIR)/ft_printf/includes $(LIBDIR)/libft
INCLUDES	= $(addprefix -I ,$(INCLUDEDIR))

all: $(NAME)

bonus: all

$(NAME): libft.a libftprintf.a $(SRC_CLIENT) $(SRC_SERVER)
	if [ $@ = "client" ]; then \
		$(CC) -o $@ $(CFLAGS) $(INCLUDES) $(SRC_CLIENT); \
	else \
		$(CC) -o $@ $(CFLAGS) $(INCLUDES) $(SRC_SERVER) $(LIBARC); \
	fi

libft.a:
	make -C $(LIBDIR)/libft
	mv $(LIBDIR)/libft/libft.a ./

libftprintf.a:
	make -C $(LIBDIR)/ft_printf
	mv $(LIBDIR)/ft_printf/libftprintf.a ./

debug: libft.a libftprintf.a $(SRC_CLIENT) $(SRC_SERVER)
	$(CC) -o client $(DFLAGS) $(INCLUDES) $(SRC_CLIENT) $(LIBARC)
	$(CC) -o server $(DFLAGS) $(INCLUDES) $(SRC_SERVER) $(LIBARC)
	./server

norm:
	norminette -R CheckForbiddenSourceHeader

setup:
	$(RM) compile_commands.json
	compiledb make
	compiledb make bonus

re: fclean all

clean:
	rm -f *.o *.a
	make -C $(LIBDIR)/libft clean
	make -C $(LIBDIR)/ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR)/libft fclean
	make -C $(LIBDIR)/ft_printf fclean

.PHONY: all clean fclean re
