/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:41:46 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/20 16:29:08 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_initialise_graphics(t_game *g_struct)
{
	g_struct->mlx = mlx_init(g_struct->width * STEP - STEP,
			g_struct->height * STEP, "GAMEBOY", true);
	g_struct->texture_back = mlx_load_png("assets/hero_back.png");
	g_struct->texture_front = mlx_load_png("assets/hero_front.png");
	g_struct->texture_left = mlx_load_png("assets/hero_left.png");
	g_struct->texture_right = mlx_load_png("assets/hero_right.png");
	g_struct->crate_texture = mlx_load_png("assets/crate.png");
	g_struct->floor_texture = mlx_load_png("assets/floor.png");
	g_struct->exit_texture = mlx_load_png("assets/closed_exit.png");
	g_struct->open_exit_texture = mlx_load_png("assets/open_exit.png");
	g_struct->col_texture = mlx_load_png("assets/coin.png");
	g_struct->enemy_texture = mlx_load_png("assets/Knight.png");
	initialise(g_struct);
}

void	initialise(t_game *g_struct)
{
	g_struct->crate = mlx_texture_to_image(g_struct->mlx,
			g_struct->crate_texture);
	g_struct->floor = mlx_texture_to_image(g_struct->mlx,
			g_struct->floor_texture);
	g_struct->collectible = mlx_texture_to_image(g_struct->mlx,
			g_struct->col_texture);
	g_struct->hero.hero_back = mlx_texture_to_image(g_struct->mlx,
			g_struct->texture_back);
	g_struct->hero.hero_left = mlx_texture_to_image(g_struct->mlx,
			g_struct->texture_left);
	g_struct->hero.hero_front = mlx_texture_to_image(g_struct->mlx,
			g_struct->texture_front);
	g_struct->hero.hero_right = mlx_texture_to_image(g_struct->mlx,
			g_struct->texture_right);
	g_struct->g_exit_img = mlx_texture_to_image(g_struct->mlx,
			g_struct->exit_texture);
	g_struct->enemy = mlx_texture_to_image(g_struct->mlx,
			g_struct->enemy_texture);
	g_struct->initialised = 1;
}

void	free_map1(t_game *g_struct)
{
	int	i;

	i = 0;
	while (g_struct->map[i])
	{
		free (g_struct->map[i]);
		i++;
	}
	free (g_struct->map);
	g_struct->map = NULL;
}

void	start_game(t_game *g_struct)
{
	set_structure(g_struct);
	ft_initialise_graphics(g_struct);
	if (!g_struct->mlx)
		exit(EXIT_FAILURE);
	ft_render_map(g_struct);
	ft_set_enemy_pos(g_struct);
	mlx_loop_hook(g_struct->mlx, &hook, g_struct);
	mlx_loop(g_struct->mlx);
	free_map(g_struct);
	mlx_terminate(g_struct->mlx);
}

void	free_map(t_game *g_struct)
{
	int	i;

	if (g_struct->enemy_count)
		free_enem_pos(g_struct);
	free_map1(g_struct);
	i = 0;
	if (g_struct->dfs)
	{	
		while (g_struct->visited[i])
		{
			free (g_struct->visited[i]);
			i++;
		}
		free (g_struct->visited);
		g_struct->visited = NULL;
	}
	if (g_struct->initialised)
	{
		delete_textures(g_struct);
		delete_images(g_struct);
	}
}
