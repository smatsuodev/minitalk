/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:35:39 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 20:41:53 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse_conversion(t_output *output)
{
	if (consume(output, 'c'))
		parse_char_conv(output);
	else if (consume(output, 's'))
		parse_str_conv(output);
	else if (consume(output, 'p'))
		parse_ptr_conv(output);
	else if (consume(output, 'd') || consume(output, 'i'))
		parse_int_conv(output);
	else if (consume(output, 'u'))
		parse_uint_conv(output);
	else if (consume(output, 'x'))
		parse_hex_conv(output, 0);
	else if (consume(output, 'X'))
		parse_hex_conv(output, 1);
	else if (consume(output, '%'))
		parse_percent_conv(output);
	else
		output->is_err = 1;
}
