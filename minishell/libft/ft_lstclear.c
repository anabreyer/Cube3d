/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:20:06 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/06/09 10:20:47 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*t;

	t = *lst;
	while (t)
	{
		temp = t->next;
		ft_lstdelone(t, del);
		t = temp;
	}
	*lst = NULL;
}
