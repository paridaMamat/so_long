/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:57:07 by pmaimait          #+#    #+#             */
/*   Updated: 2022/11/02 17:45:23 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

int	you_win(t_game *game)
{
	game->walk_cnt++;
	write(1, "you win! you run ", 17);
	ft_putnbr_fd(game->walk_cnt, 1);
	write(1, " steps.\n", 8);
	mlx_destroy_image(game->mlx, game->img.chara);
	mlx_destroy_image(game->mlx, game->img.chest);
	mlx_destroy_image(game->mlx, game->img.land);
	mlx_destroy_image(game->mlx, game->img.rune);
	mlx_destroy_image(game->mlx, game->img.rune2);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->str_line);
	free(game);
	exit (0);
}

int	get_position(t_game *game, char c)
{
	int	i;

	i = 0;
	while (i++ < game->size_all)
	{
		if (game->str_line[i] == c)
			return (i);
	}
	return (0);
}

void	move(t_game *game, int code)
{
	int	i;
	int	move;

	i = get_position(game, 'P');
	if (code == 1)
		move = i - game->wid - 1;
	else if (code == 2)
		move = i - 1;
	else if (code == 3)
		move = i + game->wid + 1;
	else if (code == 4)
		move = i + 1;
	if (game->str_line[move] == 'C')
		game->col_cnt++;
	if (game->str_line[move] == 'E' && game->all_c == game->col_cnt)
		you_win(game);
	else if (game->str_line[move] != '1' && game->str_line[move] != 'E')
	{
		game->str_line[i] = '0';
		game->str_line[move] = 'P';
		game->walk_cnt++;
		ft_putnbr_fd(game->walk_cnt, 1);
		write(1, "\n", 1);
		setting_img(game);
	}
}
