/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pathway.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:09:19 by pmaimait          #+#    #+#             */
/*   Updated: 2022/11/02 17:02:58 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

int	check_c(char *str)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(str))
	{
		if (str[i] == 'C')
			return (0);
	}
	return (1);
}

int	check_e(char *str, int y)
{
	int	x;

	x = 0;
	y = y + 1;
	while (x++ < (int)ft_strlen(str))
	{
		if (str[x] == 'E' && (str[x + 1] == 'P' || str[x - 1] == 'P'
				|| str[x + y] == 'P' || str[x - y] == 'P'))
			return (1);
	}
	return (0);
}

int	one_side_open_p(char *str, int x, int y)
{
	if (str[x] == 'P' && (str[x + 1] != '1' || str[x + 1] != 'E'
			|| str[x - 1] != '1' || str[x - 1] != 'E'
			|| str[x + y] != '1' || str[x + y] != 'E'
			|| str[x - y] != '1' || str[x - y] != 'E'))
		return (1);
	return (0);
}

int	place_i_can_reach(t_game *game, char *str)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = game->wid + 1;
	while (i++ < game->size_all)
	{
		x = 0;
		while (x++ < game->size_all)
		{
			if (one_side_open_p(str, x, y) == 1)
			{
				if (str[x + 1] != '1' && str[x + 1] != 'E' && str[x + 1] != 'P')
					str[x + 1] = 'P';
				if (str[x - 1] != '1' && str[x - 1] != 'E' && str[x - 1] != 'P')
					str[x - 1] = 'P';
				if (str[x + y] != '1' && str[x + y] != 'E' && str[x + y] != 'P')
					str[x + y] = 'P';
				if (str[x - y] != '1' && str[x - y] != 'E' && str[x - y] != 'P')
					str[x - y] = 'P';
			}
		}
	}
	return (0);
}

int	check_pathway(t_game *game)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * game->size_all + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, game->str_line, (game->size_all + 1));
	place_i_can_reach(game, str);
	if (check_e(str, game->wid) == 0 || check_c(str) == 0)
	{
		free(str);
		print_err_free(game, "there are unvalide pathway\n");
	}
	free(str);
	return (0);
}
