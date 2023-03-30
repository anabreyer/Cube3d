/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:25:59 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/06/09 10:26:41 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nl;
	t_list	*save;

	if (!lst || !f || !del)
		return (0);
	nl = ft_lstnew(f(lst->content));
	if (!nl)
		return (0);
	save = nl;
	lst = lst->next;
	while (lst)
	{
		nl->next = ft_lstnew(f(lst->content));
		if (!nl)
		{
			ft_lstclear(&save, del);
			return (0);
		}
		nl = nl->next;
		lst = lst->next;
	}
	nl->next = NULL;
	return (save);
}
