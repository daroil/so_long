/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:23:59 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/19 15:40:39 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_up(t_game *g_struct, int x, int y)
{
	char	*buf;

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
	if (g_struct->map[g_struct->hero.y / STEP][x / STEP] == 'D')
	{
		write(1, "GAMEOVER", 8);
		mlx_close_window(g_struct->mlx);
	}
	mlx_image_to_window(g_struct->mlx, g_struct->hero.hero_back,
		g_struct->hero.x, g_struct->hero.y);
	buf = ft_itoa(++g_struct->action_counter);
	mlx_image_to_window(g_struct->mlx, g_struct->crate, 0, 0);
	mlx_put_string(g_struct->mlx, buf, 0, 0);
	free(buf);
}

void	ft_move_down(t_game *g_struct, int x, int y)
{
	char	*buf;

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
	if (g_struct->map[g_struct->hero.y / STEP][x / STEP] == 'D')
	{
		write(1, "GAMEOVER", 8);
		mlx_close_window(g_struct->mlx);
	}
	mlx_image_to_window(g_struct->mlx, g_struct->hero.hero_front,
		g_struct->hero.x, g_struct->hero.y);
	buf = ft_itoa(++g_struct->action_counter);
	mlx_image_to_window(g_struct->mlx, g_struct->crate, 0, 0);
	mlx_put_string(g_struct->mlx, buf, 0, 0);
	free(buf);
}

void	ft_move_left(t_game *g_struct, int x, int y)
{
	char	*buf;

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
	if (g_struct->map[y / STEP][g_struct->hero.x / STEP] == 'D')
	{
		write(1, "GAMEOVER", 8);
		mlx_close_window(g_struct->mlx);
	}
	mlx_image_to_window(g_struct->mlx, g_struct->hero.hero_left,
		g_struct->hero.x, g_struct->hero.y);
	buf = ft_itoa(++g_struct->action_counter);
	mlx_image_to_window(g_struct->mlx, g_struct->crate, 0, 0);
	mlx_put_string(g_struct->mlx, buf, 0, 0);
	free(buf);
}

void	ft_move_right(t_game *g_struct, int x, int y)
{
	char	*buf;

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
	if (g_struct->map[y / STEP][g_struct->hero.x / STEP] == 'D')
	{
		write(1, "GAMEOVER", 8);
		mlx_close_window(g_struct->mlx);
	}
	mlx_image_to_window(g_struct->mlx, g_struct->hero.hero_right,
		g_struct->hero.x, g_struct->hero.y);
	buf = ft_itoa(++g_struct->action_counter);
	mlx_image_to_window(g_struct->mlx, g_struct->crate, 0, 0);
	mlx_put_string(g_struct->mlx, buf, 0, 0);
	free(buf);
}
