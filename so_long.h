/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:56:29 by pmaimait          #+#    #+#             */
/*   Updated: 2022/11/02 17:57:47 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define KEY_PRESS		2

# define X_EVENT_KEY_EXIT	17
# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_UP         	65362
# define KEY_DOWN       	65364
# define KEY_RIGHT      	65363
# define KEY_LEFT       	65361

typedef struct s_img
{
	void	*chara;
	void	*chest;
	void	*land;
	void	*rune;
	void	*rune2;
	void	*wall;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		wid;
	int		hei;
	char	*str_line;
	int		size_all;
	int		all_c;
	int		col_cnt;
	int		walk_cnt;
}			t_game;

// so_long
void		print_err(char *message);
void		print_err_free(t_game *game, char *message);
int			exit_game(t_game *game);
int			handle_keypress(int key_press, t_game *game);
int			main(int ac, char **av);

//map
int			count_element(t_game *game);
int			check_wall(t_game *game);
int			check_map(t_game *game);
void		read_map(t_game *game, char *map);

//image
int			img_err(t_game *game);
t_img		img_init(void *mlx_ptr);
void		put_img(t_game *g, int w, int h);
void		setting_img(t_game *game);

//utils
int			ft_strlen_newline(char *str);
int			file_is_correct(char *av);
char		*ft_strjoin_solong(char *s1, char *s2);

//move
void		move(t_game *game, int code);
int			you_win(t_game *game);
int			get_position(t_game *game, char c);

//check_pathway
int			check_c(char *str);
int			check_e(char *str, int y);
int			check_pathway(t_game *game);
int			place_i_can_reach(t_game *game, char *str);
int			one_side_open_p(char *str, int x, int y);

#endif
