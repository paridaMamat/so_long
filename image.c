/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:17:39 by pmaimait          #+#    #+#             */
/*   Updated: 2022/11/02 17:11:16 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

int	img_err(t_game *game)
{
	if (!game->img.chara || !game->img.chest || !game->img.land
		|| !game->img.rune || !game->img.rune2 || !game->img.wall)
	{
		if (game->img.chara)
			mlx_destroy_image(game->mlx, game->img.chara);
		if (game->img.chest)
			mlx_destroy_image(game->mlx, game->img.chest);
		if (game->img.land)
			mlx_destroy_image(game->mlx, game->img.land);
		if (game->img.rune)
			mlx_destroy_image(game->mlx, game->img.rune);
		if (game->img.rune2)
			mlx_destroy_image(game->mlx, game->img.rune2);
		if (game->img.wall)
			mlx_destroy_image(game->mlx, game->img.wall);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game->str_line);
		free(game);
		print_err("you lost your image\n");
	}
	return (0);
}

t_img	img_init(void *mlx)
{
	t_img	img;
	int		wid;
	int		hei;

	img.chara = mlx_xpm_file_to_image(mlx, "./images/sorcerer.xpm",
			&wid, &hei);
	img.chest = mlx_xpm_file_to_image(mlx, "./images/fire.xpm",
			&wid, &hei);
	img.land = mlx_xpm_file_to_image(mlx, "./images/land2.xpm", &wid, &hei);
	img.rune = mlx_xpm_file_to_image(mlx, "./images/doorclose.xpm", &wid, &hei);
	img.rune2 = mlx_xpm_file_to_image(mlx, "./images/dooropen.xpm", &wid, &hei);
	img.wall = mlx_xpm_file_to_image(mlx, "./images/barrier.xpm", &wid, &hei);
	return (img);
}

void	put_img(t_game *g, int x, int y)
{
	int	i;

	i = y * (g->wid + 1) + x;
	if (g->str_line[i] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, x * 64, y * 64);
	else if (g->str_line[i] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img.chest, x * 64, y * 64);
	else if (g->str_line[i] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img.chara, x * 64, y * 64);
	else if (g->str_line[i] == 'E' && g->all_c == g->col_cnt)
		mlx_put_image_to_window(g->mlx, g->win, g->img.rune2, x * 64, y * 64);
	else if (g->str_line[i] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img.rune, x * 64, y * 64);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img.land, x * 64, y * 64);
}

void	setting_img(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->hei)
	{
		x = 0;
		while (x < game->wid)
		{
			put_img(game, x, y);
			x++;
		}
		y++;
	}
}
