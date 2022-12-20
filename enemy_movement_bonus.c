/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:18:56 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/20 15:28:53 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_is_at_exit(int x, int y, int enemy_x, int enemy_y)
{
	if (enemy_x == x / STEP
		&& enemy_y == y / STEP)
		return (1);
	return (0);
}

void	move_enemy_up(t_game *g_struct)
{
	int	i;

	i = 0;
	while (i < g_struct->enemy_count)
	{
		if (g_struct->map[g_struct->enemy_pos[i][1] - 1]
			[g_struct->enemy_pos[i][0]] != '1' &&
			g_struct->map[g_struct->enemy_pos[i][1] - 1]
			[g_struct->enemy_pos[i][0]] != 'D' &&
			g_struct->map[g_struct->enemy_pos[i][1] - 1]
			[g_struct->enemy_pos[i][0]] != 'C')
			ft_move_enemy_up(g_struct, g_struct->enemy_pos[i][0],
				g_struct->enemy_pos[i][1], i);
		i++;
	}
}

void	move_enemy_down(t_game *g_struct)
{
	int	i;

	i = 0;
	while (i < g_struct->enemy_count)
	{
		if (g_struct->map[g_struct->enemy_pos[i][1] + 1]
			[g_struct->enemy_pos[i][0]] != '1' &&
			g_struct->map[g_struct->enemy_pos[i][1] + 1]
			[g_struct->enemy_pos[i][0]] != 'D' &&
			g_struct->map[g_struct->enemy_pos[i][1] + 1]
			[g_struct->enemy_pos[i][0]] != 'C')
			ft_move_enemy_down(g_struct, g_struct->enemy_pos[i][0],
				g_struct->enemy_pos[i][1], i);
		i++;
	}
}

void	move_enemy_right(t_game *g_struct)
{
	int	i;

	i = 0;
	while (i < g_struct->enemy_count)
	{
		if (g_struct->map[g_struct->enemy_pos[i][1]]
			[g_struct->enemy_pos[i][0] + 1] != '1' &&
			g_struct->map[g_struct->enemy_pos[i][1]]
			[g_struct->enemy_pos[i][0] + 1] != 'D' &&
			g_struct->map[g_struct->enemy_pos[i][1]]
			[g_struct->enemy_pos[i][0] + 1] != 'C')
			ft_move_enemy_right(g_struct, g_struct->enemy_pos[i][0],
				g_struct->enemy_pos[i][1], i);
		i++;
	}
}

void	move_enemy_left(t_game *g_struct)
{
	int	i;

	i = 0;
	while (i < g_struct->enemy_count)
	{
		if (g_struct->map[g_struct->enemy_pos[i][1]]
			[g_struct->enemy_pos[i][0] - 1] != '1' &&
			g_struct->map[g_struct->enemy_pos[i][1]]
			[g_struct->enemy_pos[i][0] - 1] != 'D' &&
			g_struct->map[g_struct->enemy_pos[i][1]]
			[g_struct->enemy_pos[i][0] - 1] != 'C')
			ft_move_enemy_left(g_struct, g_struct->enemy_pos[i][0],
				g_struct->enemy_pos[i][1], i);
		i++;
	}
}
