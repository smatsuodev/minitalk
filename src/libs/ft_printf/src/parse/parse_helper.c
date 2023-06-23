/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:14:12 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/08 02:23:37 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "libft.h"

int	consume(t_output *output, char c)
{
	if (*output->fmt != c)
		return (0);
	output->fmt++;
	return (1);
}

int	parse_int(t_output *output)
{
	int	res;

	res = 0;
	while (ft_isdigit(*output->fmt))
	{
		if (res > (INT_MAX - (*output->fmt - '0')) / 10)
		{
			output->is_err = 1;
			return (0);
		}
		res = res * 10 + (*output->fmt - '0');
		output->fmt++;
	}
	return (res);
}

void	parse_ull_to_buf(t_output *output, unsigned long long value, int base)
{
	if (output->conv_type == C_PTR || output->flags & IS_ALT_FMT)
	{
		if (output->conv_type == C_HEX || output->conv_type == C_PTR)
			output->prefix = "0x";
		if (output->conv_type == C_HEX_UPPER)
			output->prefix = "0X";
	}
	output->buffer_ptr = &output->buffer[BUFFER_SIZE - 1];
	if (value == 0)
	{
		*output->buffer_ptr = '0';
		output->buffer_size = 1;
		return ;
	}
	while (value > 0)
	{
		*output->buffer_ptr-- = char_to_num(value % base,
				output->conv_type == C_HEX_UPPER);
		value /= base;
		output->buffer_size++;
	}
	output->buffer_ptr++;
}

char	char_to_num(unsigned long long n, int is_upper)
{
	const char	*digits = "0123456789abcdef";
	char		res;

	res = digits[n];
	if (is_upper)
		return (ft_toupper(res));
	return (res);
}
