/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:41:46 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/19 19:40:38 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	delete_textures(t_game *g_struct)
{
	mlx_delete_texture(g_struct->crate_texture);
	mlx_delete_texture(g_struct->texture_back);
	mlx_delete_texture(g_struct->texture_front);
	mlx_delete_texture(g_struct->texture_right);
	mlx_delete_texture(g_struct->texture_left);
	mlx_delete_texture(g_struct->floor_texture);
	mlx_delete_texture(g_struct->col_texture);
	mlx_delete_texture(g_struct->exit_texture);
	mlx_delete_texture(g_struct->open_exit_texture);
	mlx_delete_texture(g_struct->enemy_texture);
}

void	start_game(t_game *g_struct)
{
	set_structure(g_struct);
	ft_initialise_graphics(g_struct);
	if (!g_struct->mlx)
		exit(EXIT_FAILURE);
	ft_render_map(g_struct);
	mlx_loop_hook(g_struct->mlx, &hook, g_struct);
	mlx_loop(g_struct->mlx);
	free_map(g_struct);
	mlx_terminate(g_struct->mlx);
}

void	free_map(t_game *g_struct)
{
	int	i;

	free_map1(g_struct);
	i = 0;
	while (g_struct->visited[i])
	{
		free (g_struct->visited[i]);
		i++;
	}
	free (g_struct->visited);
	g_struct->visited = NULL;
	delete_textures(g_struct);
	mlx_delete_image(g_struct->mlx, g_struct->crate);
	mlx_delete_image(g_struct->mlx, g_struct->floor);
	mlx_delete_image(g_struct->mlx, g_struct->collectible);
	mlx_delete_image(g_struct->mlx, g_struct->g_exit_img);
	mlx_delete_image(g_struct->mlx, g_struct->hero.hero_front);
	mlx_delete_image(g_struct->mlx, g_struct->hero.hero_back);
	mlx_delete_image(g_struct->mlx, g_struct->hero.hero_right);
	mlx_delete_image(g_struct->mlx, g_struct->hero.hero_left);
}
