/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:44:28 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/11/14 15:55:49 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define W 119
# define UP 65362
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363
# define A 97
# define LEFT 65361
# define ESC 65307
# define CLOSERED 33

typedef struct s_long
{
	char			**map;
	int				xscreen;
	int				yscreen;
	int				x;
	int				y;
	int				oldx;
	int				collectibleparse;
	int				exitparse;
	int				player_x;
	int				player_y;
	int				lastplayer_x;
	int				lastplayer_y;
	int				collectible;
	int				collectibletotal;
	int				move;
	int				playerset;
	int				exitset;
	int				collectibleset;

	char			*pxl;
	int				bpp;
	int				s_line;
	double			casetotal;
	double			casein;
	int				ed;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				maptofree;

	int				bpp_text[10];
	int				sline_text[10];
	int				ed_text[10];
	char			*ptr_text[5];
	void			*text[5];
	int				widthtext[10];
	int				heighttext[10];
	int				actualtext;
	unsigned int	color;
	char			*line;
}					t_long;

char	*recurs(int depth, int *ret, int fd);
int		get_next_line(int fd, char **out);
size_t	ft_strlen(const char *s);

int		get_x_and_y(t_long *sl, char *argv);
int		visible(t_long *sl);
char	*ft_strcpy(char *dest, char *src);
int		parsing(t_long *sl, char *argv);
int		stockmap(t_long *sl, char *argv);
int		mallocmap(t_long *sl);
int		render_calcul(t_long *sl);
int		render(t_long *sl);
void	floodandfill2(t_long *sl, int mapy, int mapx);
int		checkmap(t_long *sl);
int		numberblank(char *str);
int		get_next_line(int fd, char **line);
int		printtexture(t_long *sl, int starter_X, int starter_Y);
int		showerror(t_long *sl, char *str);
int		checkcubextension(char *str, t_long *sl);
int		pos_player(t_long *sl);
void	ft_putstr(char *str);
int		initplayer(t_long *sl);
int		loadtexture(t_long *sl);
int		loadtexture3(t_long *sl);
int		gettextnum(int X, int Y, t_long *sl);
int		moveplayer(int nb, t_long *sl);
int		checkaremove(t_long *sl);
int		stockline(t_long *sl, char *line, int nb);
int		checkifgood(char c);
void	ft_putchar(char c);
char	replacechar(char c);
void	ft_putnbr(int nb);
int		checkthewall(t_long *sl);
int		floodandfill(t_long *sl, int mapy, int mapx);
int		displaymove(t_long *sl, int nb);
int		freemap(t_long *sl);
void	resetkeyboard(t_long *sl);
int		checkaround(int mapx, int mapy, t_long *sl);
int		ft_key_hit(int keycode, t_long *sl);
int		ft_key_release(int keycode, t_long *sl);
int		ft_keyboard(int keycode, t_long *display);
int		closebyredbutton(t_long *sl);
int		freeandexit(t_long *sl);
int		display(t_long *sl);
int		go_hooking(t_long *sl);
int		createwindow(t_long *sl);
int		put_pxl(t_long *sl, int x, int y, unsigned int c);
int		initvar(t_long *sl);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);

#endif
