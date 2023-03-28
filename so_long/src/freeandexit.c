/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:57:23 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/11/14 15:58:01 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	freeandexit(t_long *sl)
{
	int	i;

	i = 0;
	if (sl->mlx_ptr != NULL)
	{
		mlx_destroy_image(sl->mlx_ptr, sl->img);
		mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
		while (i < 5)
		{
			mlx_destroy_image(sl->mlx_ptr, sl->text[i]);
			i++;
		}
		mlx_destroy_display(sl->mlx_ptr);
		free(sl->mlx_ptr);
		free(sl->line);
	}
	freemap(sl);
	exit(0);
}

int	freemap(t_long *sl)
{
	int	i;

	i = 0;
	if (sl->maptofree == -1)
		return (1);
	while (i < sl->y)
	{
		free(sl->map[i]);
		i++;
	}
	if (sl->map)
		free(sl->map);
	return (0);
}

int	showerror(t_long *sl, char *str)
{
	write(1, "\033[31mError\n\033[0;37m", 12);
	ft_putstr(str);
	write(1, "\n", 1);
	freeandexit(sl);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	char			*ptr;

	if (!s1)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1_len-- != 0)
		ptr[i++] = *s1++;
	while (s2_len-- != 0)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}
