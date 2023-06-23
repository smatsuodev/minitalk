/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:44:56 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/25 22:10:37 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_digits(long long n)
{
	size_t	num_digits;

	num_digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		num_digits++;
	}
	while (n > 0)
	{
		n /= 10;
		num_digits++;
	}
	return (num_digits);
}

static char	*ft_lltoa(long long n)
{
	size_t	num_digits;
	char	*s;
	char	*head;
	char	*tail;

	num_digits = count_digits(n);
	s = ft_calloc(num_digits + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	head = s;
	tail = head + num_digits;
	if (n < 0)
	{
		*head++ = '-';
		n *= -1;
	}
	while (tail-- != head)
	{
		*tail = n % 10 + '0';
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	return (ft_lltoa(n));
}
