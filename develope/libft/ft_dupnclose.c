/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupnclose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <jischoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 06:12:26 by ykuo              #+#    #+#             */
/*   Updated: 2023/04/19 15:03:45 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dupnclose(int oldfd, int newfd)
{
	dup2(oldfd, newfd);
	ft_close(oldfd);
}