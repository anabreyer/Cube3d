/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:43:38 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/06/08 11:44:02 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*srcp;

	srcp = (char *)src;
	i = 0;
	while (i < size && *dest)
	{
		dest++;
		i++;
	}
	if (i == size)
		return (i + ft_strlen(src));
	j = 0;
	while (srcp[j])
	{
		if (j < size - i - 1)
			*dest++ = srcp[j];
		j++;
	}
	*dest = 0;
	return (i + j);
}
