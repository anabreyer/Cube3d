/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:27:09 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/06/09 10:27:19 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*thingy;

	thingy = (t_list *)malloc(sizeof(t_list));
	if (!thingy)
		return (NULL);
	thingy->next = NULL;
	thingy->content = content;
	return (thingy);
}
