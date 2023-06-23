/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:32:08 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 22:52:04 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse_hex_conv(t_output *output, int is_upper)
{
	unsigned int	arg;

	if (is_upper)
		output->conv_type = C_HEX_UPPER;
	else
		output->conv_type = C_HEX;
	arg = va_arg(*output->args, unsigned int);
	parse_ull_to_buf(output, (unsigned long long)arg, 16);
}
