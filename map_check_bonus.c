/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:05:23 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/19 15:40:32 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlen_nonl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	ft_is_rectangular(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen_nonl(map[i]) != ft_strlen_nonl(map[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_last(char **map, int i)
{
	int	j;

	j = 0;
	i--;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != '\n')
			return (0);
		j++;
	}
	return (1);
}

int	ft_map_closed_walls(char **map)
{
	int	i;
	int	j;
	int	exit;

	exit = 0;
	i = -1;
	while (map[++i])
	{
		j = 0;
		if (map[i][j] != '1')
			return (0);
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			if (map[0][j] != '1' && map[0][j] != '\n')
				return (0);
			j++;
		}
		if (map[i][j - 2] != '1')
			return (0);
	}
	if (exit != 1 || !ft_check_last(map, i))
		return (0);
	return (1);
}

void	ft_copy_array(char *path, t_game *g_struct)
{
	int		fd;
	int		width;
	int		height;
	char	*line;

	height = 0;
	g_struct->visited = malloc (sizeof(char *) * ft_count_height(path) + 1);
	fd = open(path, 'r');
	line = get_next_line(fd);
	width = ft_strlen(line);
	if (!g_struct->visited)
		free(g_struct->visited);
	while (line)
	{
		if (line != NULL)
			g_struct->visited[height] = line;
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	g_struct->visited[height] = NULL;
}
