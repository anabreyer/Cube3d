/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:45:32 by ykuo              #+#    #+#             */
/*   Updated: 2023/04/19 15:03:37 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ans;

	ans = malloc (nmemb * size);
	if (!ans)
		return (0);
	ft_bzero((void *)ans, (nmemb * size));
	return ((void *)ans);
}
