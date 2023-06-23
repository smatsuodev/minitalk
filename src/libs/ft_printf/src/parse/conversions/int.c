/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:46:23 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 22:55:48 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse_int_conv(t_output *output)
{
	long long	arg;

	output->conv_type = C_INT;
	arg = va_arg(*output->args, int);
	if (arg >= 0 && (output->flags & IS_FORCE_PLUS))
		output->sign = '+';
	if (arg >= 0 && (output->flags & IS_FORCE_SPACE))
		output->sign = ' ';
	if (arg < 0)
	{
		output->sign = '-';
		arg *= -1;
	}
	parse_ull_to_buf(output, (unsigned long long)arg, 10);
}
