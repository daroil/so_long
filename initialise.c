/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:10:27 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/20 16:54:55 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_delete_texture(g_struct->texture);
	mlx_delete_texture(g_struct->floor_texture);
	mlx_delete_texture(g_struct->col_texture);
	mlx_delete_texture(g_struct->exit_texture);
	mlx_delete_texture(g_struct->open_exit_texture);
}

void	free_map(t_game *g_struct)
{
	int	i;

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
		mlx_delete_image(g_struct->mlx, g_struct->crate);
		mlx_delete_image(g_struct->mlx, g_struct->floor);
		mlx_delete_image(g_struct->mlx, g_struct->collectible);
		mlx_delete_image(g_struct->mlx, g_struct->g_exit_img);
		mlx_delete_image(g_struct->mlx, g_struct->hero.hero);
	}
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
