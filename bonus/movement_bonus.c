/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:56:01 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/20 15:23:34 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_if_all(t_game *g_struct)
{
	int	x;
	int	y;

	if (g_struct->collected == g_struct->all_collectibles)
	{
		x = g_struct->g_exit_img->instances->x;
		y = g_struct->g_exit_img->instances->y;
		g_struct->g_exit_img = mlx_texture_to_image(g_struct->mlx,
				g_struct->open_exit_texture);
		mlx_image_to_window(g_struct->mlx, g_struct->floor, x, y);
		mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, x, y);
		return (1);
	}
	return (0);
}

void	ft_go_up(mlx_key_data_t keydata, void *param)
{
	t_game	*g_struct;

	g_struct = (t_game *)param;
	if (keydata.action == MLX_RELEASE)
	{
		if (g_struct->map[g_struct->hero.y / STEP - 1]
			[g_struct->hero.x / STEP] != '1')
			ft_move_up(g_struct, g_struct->hero.x, g_struct->hero.y);
		move_enemy_up(g_struct);
	}
}

void	ft_go_down(mlx_key_data_t keydata, void *param)
{
	t_game	*g_struct;

	g_struct = (t_game *)param;
	if (keydata.action == MLX_RELEASE)
	{
		if (g_struct->map[g_struct->hero.y / STEP + 1]
			[g_struct->hero.x / STEP] != '1')
			ft_move_down(g_struct, g_struct->hero.x, g_struct->hero.y);
		move_enemy_down(g_struct);
	}
}

void	ft_go_left(mlx_key_data_t keydata, void *param)
{
	t_game	*g_struct;

	g_struct = (t_game *)param;
	if (keydata.action == MLX_RELEASE)
	{
		if (g_struct->map[g_struct->hero.y / STEP]
			[g_struct->hero.x / STEP - 1] != '1')
			ft_move_left(g_struct, g_struct->hero.x, g_struct->hero.y);
		move_enemy_left(g_struct);
	}
}

void	ft_go_right(mlx_key_data_t keydata, void *param)
{
	t_game	*g_struct;

	g_struct = (t_game *)param;
	if (keydata.action == MLX_RELEASE)
	{
		if (g_struct->map[g_struct->hero.y / STEP]
			[g_struct->hero.x / STEP + 1] != '1')
			ft_move_right(g_struct, g_struct->hero.x, g_struct->hero.y);
		move_enemy_right(g_struct);
	}
}
