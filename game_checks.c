/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:15:36 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/17 12:31:39 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hit_an_exit(int x, int y, t_game *g_struct)
{
	if (g_struct->hero.x / STEP == x / STEP
		&& g_struct->hero.y / STEP == y / STEP
		&& g_struct->exit_open == 1)
		return (1);
	return (0);
}

int	is_at_exit(int x, int y, t_game *g_struct)
{
	if (g_struct->hero.x / STEP == x / STEP
		&& g_struct->hero.y / STEP == y / STEP)
		return (1);
	return (0);
}

void	free_map(t_game *g_struct)
{
	int	i;

	i = 0;
	while (g_struct->map[i])
	{
		free (g_struct->map[i]);
		i++;
	}
	free (g_struct->map);
}

int	player_check(char **map)
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
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}
