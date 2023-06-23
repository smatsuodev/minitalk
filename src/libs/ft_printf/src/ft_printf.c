/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:07:25 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/20 01:08:20 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_output	output;

	va_start(ap, fmt);
	init_output(&output);
	output.fmt = (char *)fmt;
	output.args = &ap;
	parse(&output);
	return (output.written_size);
}
