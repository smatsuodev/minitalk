/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:48:23 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 22:51:02 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse_uint_conv(t_output *output)
{
	unsigned int	arg;

	output->conv_type = C_UINT;
	arg = va_arg(*output->args, unsigned int);
	if (output->flags & IS_FORCE_PLUS)
		output->sign = '+';
	if (output->flags & IS_FORCE_SPACE)
		output->sign = ' ';
	parse_ull_to_buf(output, arg, 10);
}
