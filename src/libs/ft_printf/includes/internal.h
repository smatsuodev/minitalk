/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:18:18 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 23:27:46 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

# define BUFFER_SIZE 32

typedef enum e_flag
{
	IS_ALT_FMT = 0b1,
	IS_ZEROFILL = 0b10,
	IS_ALIGNLEFT = 0b100,
	IS_FORCE_SPACE = 0b1000,
	IS_FORCE_PLUS = 0b10000
}	t_flag;

typedef enum e_type
{
	C_INT,
	C_UINT,
	C_CHAR,
	C_STR,
	C_PTR,
	C_HEX,
	C_HEX_UPPER,
	C_PERCENT
}	t_type;

typedef struct s_output
{
	int			is_err;
	char		*fmt;
	va_list		*args;
	char		buffer[BUFFER_SIZE];
	char		*buffer_ptr;
	t_type		conv_type;
	int			flags;
	int			written_size;
	int			buffer_size;
	int			min_field_width;
	int			precision;
	char		padding;
	char		sign;
	char		*prefix;
}	t_output;
void	init_output(t_output *output);
void	reset_buffer(t_output *output);

void	parse(t_output *output);
void	parse_flags(t_output *output);
void	parse_min_field_width(t_output *output);
void	parse_precision(t_output *output);
void	parse_conversion(t_output *output);
int		consume(t_output *output, char c);
int		parse_int(t_output *output);
void	parse_ull_to_buf(t_output *output, unsigned long long value, int base);
char	char_to_num(unsigned long long n, int is_upper);

void	parse_char_conv(t_output *output);
void	parse_str_conv(t_output *output);
void	parse_ptr_conv(t_output *output);
void	parse_int_conv(t_output *output);
void	parse_uint_conv(t_output *output);
void	parse_hex_conv(t_output *output, int is_upper);
void	parse_percent_conv(t_output *output);

int		content_size(t_output *output);
int		precise_content_size(t_output *output);

void	print(t_output *output);
void	print_min_field_width(t_output *output);
void	print_sign(t_output *output);
void	print_content(t_output *output);

void	put_char(t_output *output, char c);
void	put_char_rep(t_output *output, char c, int times);
void	put_str(t_output *output, char *s);
void	put_strn(t_output *output, char *s, size_t len);

int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif
