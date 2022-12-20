/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:02:33 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/20 16:29:00 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_render_chars(char *line, int y, t_game *g_struct)
{
	int	x;

	x = 0;
	while (*line)
	{
		if (*line == '1')
			mlx_image_to_window(g_struct->mlx, g_struct->crate, x, y);
		if (*line == '0' || *line == 'C' || *line == 'P' || *line == 'D')
			mlx_image_to_window(g_struct->mlx, g_struct->floor, x, y);
		if (*line == 'C')
			mlx_image_to_window(g_struct->mlx, g_struct->collectible, x, y);
		if (*line == 'P')
		{
			g_struct->hero.x = x;
			g_struct->hero.y = y;
		}
		if (*line == 'E')
			mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, x, y);
		if (*line == 'D')
			mlx_image_to_window(g_struct->mlx, g_struct->enemy, x, y);
		x += STEP;
		line++;
	}
}

void	ft_render_map(t_game *g_struct)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (g_struct->map[x])
	{
		if (g_struct->map[x] != NULL)
			ft_render_chars(g_struct->map[x], y, g_struct);
		y += STEP;
		x++;
	}
	mlx_image_to_window(g_struct->mlx, g_struct->hero.hero_front,
		g_struct->hero.x, g_struct->hero.y);
}

int	ft_count_height(char *path)
{
	int		fd;
	int		height;
	char	*line;

	fd = open (path, 'r');
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	return (height);
}

void	ft_create_array(char *path, t_game *g_struct)
{
	int		fd;
	char	*line;
	int		i;

	g_struct->height = 0;
	g_struct->map = malloc(sizeof(char *) * ft_count_height(path) + 1);
	fd = open (path, 'r');
	line = get_next_line(fd);
	g_struct->width = ft_strlen(line);
	if (!g_struct->map)
		free(g_struct->map);
	i = 0;
	while (line)
	{
		if (line != NULL)
			g_struct->map[i] = line;
		line = get_next_line(fd);
		g_struct->height++;
		i++;
	}
	close(fd);
	g_struct->map[g_struct->height] = NULL;
	g_struct->initialised = 0;
	g_struct->enemy_count = 0;
}
