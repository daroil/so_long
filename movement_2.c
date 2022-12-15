/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:23:59 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/15 23:30:31 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *g_struct, int x, int y)
{
	mlx_image_to_window(g_struct->mlx, g_struct->floor, x, y);
	if (is_at_exit(g_struct->g_exit_img->instances->x,
			g_struct->g_exit_img->instances->y, g_struct))
		mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, x, y);
	g_struct->hero.y -= STEP;
	if (g_struct->map[g_struct->hero.y / STEP][x / STEP] == 'C')
	{
		g_struct->collected++;
		g_struct->map[g_struct->hero.y / STEP][x / STEP] = '0';
		if (check_if_all(g_struct) && g_struct->exit_open == 0)
			g_struct->exit_open = 1;
	}
	mlx_image_to_window(g_struct->mlx, g_struct->hero.hero,
		g_struct->hero.x, g_struct->hero.y);
	ft_printf("Actions taken:%d\n", ++g_struct->action_counter);
}

void	ft_move_down(t_game *g_struct, int x, int y)
{
	mlx_image_to_window(g_struct->mlx, g_struct->floor, x, y);
	if (is_at_exit(g_struct->g_exit_img->instances->x,
			g_struct->g_exit_img->instances->y, g_struct))
		mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, x, y);
	g_struct->hero.y += STEP;
	if (g_struct->map[g_struct->hero.y / STEP][x / STEP] == 'C')
	{
		g_struct->collected++;
		g_struct->map[g_struct->hero.y / STEP][x / STEP] = '0';
		if (check_if_all(g_struct) && g_struct->exit_open == 0)
			g_struct->exit_open = 1;
	}
	mlx_image_to_window(g_struct->mlx, g_struct->hero.hero,
		g_struct->hero.x, g_struct->hero.y);
	ft_printf("Actions taken:%d\n", ++g_struct->action_counter);
}

void	ft_move_left(t_game *g_struct, int x, int y)
{
	mlx_image_to_window(g_struct->mlx, g_struct->floor, x, y);
	if (is_at_exit(g_struct->g_exit_img->instances->x,
			g_struct->g_exit_img->instances->y, g_struct))
		mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, x, y);
	g_struct->hero.x -= STEP;
	if (g_struct->map[y / STEP][g_struct->hero.x / STEP] == 'C')
	{
		g_struct->collected++;
		g_struct->map[y / STEP][g_struct->hero.x / STEP] = '0';
		if (check_if_all(g_struct) && g_struct->exit_open == 0)
			g_struct->exit_open = 1;
	}
	mlx_image_to_window(g_struct->mlx, g_struct->hero.hero,
		g_struct->hero.x, g_struct->hero.y);
	ft_printf("Actions taken:%d\n", ++g_struct->action_counter);
}

void	ft_move_right(t_game *g_struct, int x, int y)
{
	mlx_image_to_window(g_struct->mlx, g_struct->floor, x, y);
	if (is_at_exit(g_struct->g_exit_img->instances->x,
			g_struct->g_exit_img->instances->y, g_struct))
		mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, x, y);
	g_struct->hero.x += STEP;
	if (g_struct->map[y / STEP][g_struct->hero.x / STEP] == 'C')
	{
		g_struct->collected++;
		g_struct->map[y / STEP][g_struct->hero.x / STEP] = '0';
		if (check_if_all(g_struct) && g_struct->exit_open == 0)
			g_struct->exit_open = 1;
	}
	mlx_image_to_window(g_struct->mlx, g_struct->hero.hero,
		g_struct->hero.x, g_struct->hero.y);
	ft_printf("Actions taken:%d\n", ++g_struct->action_counter);
}
