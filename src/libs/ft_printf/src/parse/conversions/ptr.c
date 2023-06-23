/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:43:15 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 20:04:02 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse_ptr_conv(t_output *output)
{
	void	*arg;

	output->conv_type = C_PTR;
	arg = va_arg(*output->args, void *);
	parse_ull_to_buf(output, (unsigned long long)arg, 16);
}
