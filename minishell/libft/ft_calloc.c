/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:41:07 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/06/08 12:09:03 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dest;

	if (size != 0 && ((int)(count * size) / size) != count)
		return (NULL);
	tot_size = size * count;
	dest = malloc(tot_size);
	if (!(dest))
		return (0);
	ft_memset(dest, 0, tot_size);
	return (dest);
}
