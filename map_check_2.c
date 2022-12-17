/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:08:03 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/17 12:28:53 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_coll_exit(char **visited)
{
	int	i;
	int	j;

	i = 0;
	while (visited[i])
	{
		j = 0;
		while (visited[i][j])
		{
			if (visited[i][j] == 'C' || visited[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_get_player_pos(char **map, t_game *g_struct)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				g_struct->hero.x = j;
				g_struct->hero.y = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_wrong_symbols(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P'
			&& map[i][j] != '0'
			&& map[i][j] != 'E'
			&& map[i][j] != '\n'
			&& map[i][j] != 'C'
			&& map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_map(char *path, t_game *g_struct)
{
	if (ft_wrong_symbols(g_struct->map))
		return (0);
	if (ft_is_rectangular(g_struct->map))
	{
		if (ft_map_closed_walls(g_struct->map))
		{
			if (player_check(g_struct->map))
			{	
				ft_copy_array(path, g_struct);
				ft_get_player_pos(g_struct->map, g_struct);
				dfs(g_struct, g_struct->hero.y, g_struct->hero.x);
				if (ft_check_coll_exit(g_struct->visited))
					return (1);
			}
		}
	}
	return (0);
}

int	ft_count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
