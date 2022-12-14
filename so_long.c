/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:08:45 by pmaimait          #+#    #+#             */
/*   Updated: 2022/11/02 17:48:38 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

void	print_err(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

void	print_err_free(t_game *game, char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	free(game->str_line);
	free(game);
	exit(1);
}

int	exit_game(t_game *game)
{
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

int	handle_keypress(int key_press, t_game *game)
{
	if (key_press == KEY_ESC)
		exit_game(game);
	if (key_press == KEY_W || key_press == KEY_UP)
		move(game, 1);
	if (key_press == KEY_A || key_press == KEY_LEFT)
		move(game, 2);
	if (key_press == KEY_S || key_press == KEY_DOWN)
		move(game, 3);
	if (key_press == KEY_D || key_press == KEY_RIGHT)
		move(game, 4);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		print_err("Map is missing.\n");
	if (file_is_correct(av[1]) == 0)
		print_err("map's format is not .ber\n");
	game = malloc(sizeof(t_game));
	read_map(game, av[1]);
	check_map(game);
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	img_err(game);
	game->win = mlx_new_window(game->mlx, game->wid * 64,
			game->hei * 64, "so_long");
	setting_img(game);
	game->walk_cnt = 0;
	mlx_hook(game->win, KEY_PRESS, 1L << 0, &handle_keypress, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1L << 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
