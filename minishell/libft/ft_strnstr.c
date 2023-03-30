/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:49:08 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/06/08 11:49:24 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!*s1 && !*s2) || !*s2)
		return ((char *)s1);
	if (!*s1)
		return (0);
	j = 0;
	while (j < len && len != 0 && *s1)
	{
		if (*s1 == *s2)
		{
			i = 1;
			while (s2[i] == s1[i] && s2[i] && j + i < len)
				i++;
			if (!s2[i])
				return ((char *)s1);
		}
		s1++;
		j++;
	}
	return (NULL);
}
