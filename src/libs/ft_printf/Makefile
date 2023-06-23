NAME     		= libftprintf.a
LIBFT_PATH		= ./libft
LIBFT_A			= ./libft/libft.a
LIBFT_FILES		= libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c
LIBFT_OBJECTS	= $(LIBFT_FILES:.c=.o)
EXEC_BIN_NAME	= a.out

MANDATORY_DIR	= .
CFLAGS   		= -Wall -Wextra -Werror
CFLAGS_DEBUG	= $(CFLAGS) -g -fsanitize=address,undefined
INCLUDE_DIR	 	= $(MANDATORY_DIR)/includes $(LIBFT_PATH)
INCLUDE_OPTION	= $(addprefix -I ,$(INCLUDE_DIR))
INCLUDE_FILES	= $(addsuffix /*.h,$(INCLUDE_DIR))
SRC_FILES    	= src/ft_printf.c src/output/output_helper.c src/parse/conversion.c src/parse/conversions/char.c src/parse/conversions/hex.c src/parse/conversions/int.c src/parse/conversions/percent.c src/parse/conversions/ptr.c src/parse/conversions/str.c src/parse/conversions/uint.c src/parse/flags.c src/parse/min_field_width.c src/parse/parse.c src/parse/parse_helper.c src/parse/precision.c src/print/print.c src/put/put.c src/utils/utils.c
SRC_OBJECTS  	= $(SRC_FILES:.c=.o)

BONUS_DIR				= $(MANDATORY_DIR)
BONUS_INCLUDES	 		= $(INCLUDE_DIR)
BONUS_INCLUDE_OPTION	= $(INCLUDE_OPTION)
BONUS_INCLUDE_FILES		= $(INCLUDE_FILES)
BONUS_SRC_FILES    		= $(SRC_FILES)
BONUS_SRC_OBJECTS  		= $(SRC_OBJECTS)

RM	= rm -f
CC	= cc

all: $(NAME)

$(NAME): $(SRC_OBJECTS) $(LIBFT_OBJECTS)
	ar rc $(NAME) $(SRC_OBJECTS) $(LIBFT_OBJECTS)

bonus: all

$(LIBFT_OBJECTS):
	make -C $(LIBFT_PATH)

%_bonus.o: %_bonus.c
	$(CC) $(BONUS_INCLUDE_OPTION) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(INCLUDE_OPTION) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC_OBJECTS)
	$(RM) $(BONUS_SRC_OBJECTS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

setup:
	$(RM) compile_commands.json
	compiledb make
	compiledb make bonus

main: $(SRC_FILES) $(LIBFT_A)
	$(CC) $(INCLUDE_OPTION) $(CFLAGS) -o $(EXEC_BIN_NAME) $^ $(LIBFT_A)
	./$(EXEC_BIN_NAME)

debug: $(SRC_FILES) $(LIBFT_A)
	$(CC) $(INCLUDE_OPTION) $(CFLAGS_DEBUG) -o $(EXEC_BIN_NAME) $^ $(LIBFT_A)
	./$(EXEC_BIN_NAME)

bmain: $(BONUS_SRC_FILES) $(LIBFT_A)
	$(CC) $(BONUS_INCLUDE_OPTION) $(CFLAGS) -o $(EXEC_BIN_NAME) $^
	./$(EXEC_BIN_NAME)

bdebug: $(BONUS_SRC_FILES) $(LIBFT_A)
	$(CC) $(BONUS_INCLUDE_OPTION) $(CFLAGS_DEBUG) -o $(EXEC_BIN_NAME) $^
	./$(EXEC_BIN_NAME)

norm:
	norminette $(SRCS_FILES) $(INCLUDE_FILES) $(BONUS_SRC_FILES) $(BONUS_INCLUDE_FILES)

.PHONY: all main debug setup clean fclean re norm
