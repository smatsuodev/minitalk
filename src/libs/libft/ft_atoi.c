/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:29:03 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/25 17:09:25 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_out_of_range(const char *str, int is_neg)
{
	size_t	digits_num;

	digits_num = 0;
	while (ft_isdigit(str[digits_num]))
		digits_num++;
	if (digits_num > ft_strlen("9223372036854775807"))
		return (1);
	if (digits_num < ft_strlen("9223372036854775807"))
		return (0);
	if (is_neg)
		return (ft_strncmp(str, "9223372036854775808",
				ft_strlen("9223372036854775808")) > 0);
	return (ft_strncmp(str, "9223372036854775807",
			ft_strlen("9223372036854775807")) > 0);
}

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	while (**str == '0')
		(*str)++;
	return (sign);
}

static int	isspace(const char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	while (isspace(*str))
		str++;
	sign = get_sign(&str);
	if (is_out_of_range(str, sign == -1))
	{
		if (sign == 1)
			return ((int)LONG_MAX);
		return ((int)LONG_MIN);
	}
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return ((int)(result * sign));
}
