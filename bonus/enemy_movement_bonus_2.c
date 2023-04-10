/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:23:09 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/20 15:23:42 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_move_enemy_up(t_game *g_struct, int x, int y, int i)
{
	mlx_image_to_window(g_struct->mlx, g_struct->floor, x * STEP, y * STEP);
	if (enemy_is_at_exit(g_struct->g_exit_img->instances->x,
			g_struct->g_exit_img->instances->y, x, y))
		mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img,
			x * STEP, y * STEP);
	g_struct->map[g_struct->enemy_pos[i][1]]
	[g_struct->enemy_pos[i][0]] = '0';
	g_struct->enemy_pos[i][1] -= 1;
	g_struct->map[g_struct->enemy_pos[i][1]]
	[g_struct->enemy_pos[i][0]] = 'D';
	mlx_image_to_window(g_struct->mlx, g_struct->enemy,
		g_struct->enemy_pos[i][0] * STEP, g_struct->enemy_pos[i][1] * STEP);
}

void	ft_move_enemy_down(t_game *g_struct, int x, int y, int i)
{
	mlx_image_to_window(g_struct->mlx, g_struct->floor, x * STEP, y * STEP);
	if (enemy_is_at_exit(g_struct->g_exit_img->instances->x,
			g_struct->g_exit_img->instances->y, x, y))
		mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img,
			x * STEP, y * STEP);
	g_struct->map[g_struct->enemy_pos[i][1]]
	[g_struct->enemy_pos[i][0]] = '0';
	g_struct->enemy_pos[i][1] += 1;
	g_struct->map[g_struct->enemy_pos[i][1]]
	[g_struct->enemy_pos[i][0]] = 'D';
	mlx_image_to_window(g_struct->mlx, g_struct->enemy,
		g_struct->enemy_pos[i][0] * STEP, g_struct->enemy_pos[i][1] * STEP);
}

void	ft_move_enemy_right(t_game *g_struct, int x, int y, int i)
{
	mlx_image_to_window(g_struct->mlx, g_struct->floor, x * STEP, y * STEP);
	if (enemy_is_at_exit(g_struct->g_exit_img->instances->x,
			g_struct->g_exit_img->instances->y, x, y))
		mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img,
			x * STEP, y * STEP);
	g_struct->map[g_struct->enemy_pos[i][1]]
	[g_struct->enemy_pos[i][0]] = '0';
	g_struct->enemy_pos[i][0] += 1;
	g_struct->map[g_struct->enemy_pos[i][1]]
	[g_struct->enemy_pos[i][0]] = 'D';
	mlx_image_to_window(g_struct->mlx, g_struct->enemy,
		g_struct->enemy_pos[i][0] * STEP, g_struct->enemy_pos[i][1] * STEP);
}

void	ft_move_enemy_left(t_game *g_struct, int x, int y, int i)
{
	mlx_image_to_window(g_struct->mlx, g_struct->floor, x * STEP, y * STEP);
	if (enemy_is_at_exit(g_struct->g_exit_img->instances->x,
			g_struct->g_exit_img->instances->y, x, y))
		mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img,
			x * STEP, y * STEP);
	g_struct->map[g_struct->enemy_pos[i][1]]
	[g_struct->enemy_pos[i][0]] = '0';
	g_struct->enemy_pos[i][0] -= 1;
	g_struct->map[g_struct->enemy_pos[i][1]]
	[g_struct->enemy_pos[i][0]] = 'D';
	mlx_image_to_window(g_struct->mlx, g_struct->enemy,
		g_struct->enemy_pos[i][0] * STEP, g_struct->enemy_pos[i][1] * STEP);
}
