/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:17:28 by pmaimait          #+#    #+#             */
/*   Updated: 2022/11/02 17:37:30 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minilibx-linux/mlx.h"
#include "so_long.h"

int	count_element(t_game *game)
{
	int	countp;
	int	counte;
	int	i;

	i = 0;
	countp = 0;
	counte = 0;
	game->all_c = 0;
	game->col_cnt = 0;
	while (game->str_line[i++])
	{
		if (game->str_line[i] == 'C')
			game->all_c++;
		if (game->str_line[i] == 'P')
			countp++;
		if (game->str_line[i] == 'E')
			counte++;
	}
	if (countp != 1 || counte != 1)
		print_err_free(game,
			"map must have only or at least one Player and one Exit\n");
	if (game->all_c < 1)
		print_err_free(game, "map must have at least one collection\n");
	return (0);
}

int	check_element(t_game *game)
{
	int	i;

	i = 0;
	while (game->str_line[i++])
	{
		if (game->str_line[i] != 'C' && game->str_line[i] != 'P'
			&& game->str_line[i] != 'E' && game->str_line[i] != '0'
			&& game->str_line[i] != '1' && game->str_line[i] != '\n'
			&& game->str_line[i] != '\0')
			print_err_free(game, "there is a invalid element in your map\n");
	}
	return (0);
}

int	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size_all)
	{
		if (i < game->wid || (i > (game->size_all - game->wid)))
		{
			if (game->str_line[i] != '1')
				print_err_free(game, "map must be surrounded by wall\n");
		}
		if (game->str_line[i] == '\n' && (game->str_line[i - 1] != '1'
				|| game->str_line[i + 1] != '1'))
			print_err_free(game, "map must be surrounded by wall\n");
		i++;
	}
	return (0);
}

int	check_map(t_game *game)
{
	game->size_all = (int)ft_strlen(game->str_line);
	if (game->wid * game->hei != game->size_all - (game->hei - 1))
		print_err_free(game, "each line must have same size\n");
	if (game->wid == game->hei)
		print_err_free(game, "map must be rectangular\n");
	check_wall(game);
	check_element(game);
	count_element(game);
	check_pathway(game);
	return (0);
}

void	read_map(t_game *game, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd <= 0)
	{
		free(game);
		print_err("File open fail.\n");
	}
	game->hei = 0;
	game->str_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->wid = ft_strlen_newline(line);
		game->str_line = ft_strjoin_solong(game->str_line, line);
		free(line);
		game->hei++;
	}
	close(fd);
}
