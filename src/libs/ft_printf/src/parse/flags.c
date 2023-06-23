/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:18:51 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/08 02:46:04 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse_flags(t_output *output)
{
	while (ft_strchr("#0- +", *output->fmt))
	{
		if (consume(output, '#'))
			output->flags |= IS_ALT_FMT;
		if (consume(output, '0'))
			output->flags |= IS_ZEROFILL;
		if (consume(output, '-'))
			output->flags |= IS_ALIGNLEFT;
		if (consume(output, ' '))
			output->flags |= IS_FORCE_SPACE;
		if (consume(output, '+'))
			output->flags |= IS_FORCE_PLUS;
	}
	if ((output->flags & IS_ZEROFILL && output->flags & IS_ALIGNLEFT)
		|| (output->flags & IS_FORCE_SPACE && output->flags & IS_FORCE_PLUS)
		|| (output->flags & IS_ALT_FMT && output->flags & IS_FORCE_PLUS)
		|| (output->flags & IS_ALT_FMT && output->flags & IS_FORCE_SPACE))
		output->is_err = 1;
}
