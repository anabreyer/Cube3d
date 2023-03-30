/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:23:30 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/25 19:43:10 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int range(int neg, unsigned long long int num, int *error)
{
    if ((neg == 1 && num > LONG_MAX) || (neg == -1 && num > -(unsigned long)LONG_MIN))
        *error = 1;
    return (*error);
}

long ft_str_to_long(const char* str, int* error) 
{
    unsigned long long	nbr;
	int					neg;
	int					i;

	nbr = 0;
	neg = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (range(neg, nbr, error))
			break ;
		i++;
	}
	return (nbr * neg);
}