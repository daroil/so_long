/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:46:33 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/20 15:46:53 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

void	delete_images(t_game *g_struct)
{
	mlx_delete_image(g_struct->mlx, g_struct->crate);
	mlx_delete_image(g_struct->mlx, g_struct->floor);
	mlx_delete_image(g_struct->mlx, g_struct->collectible);
	mlx_delete_image(g_struct->mlx, g_struct->g_exit_img);
	mlx_delete_image(g_struct->mlx, g_struct->hero.hero_front);
	mlx_delete_image(g_struct->mlx, g_struct->hero.hero_back);
	mlx_delete_image(g_struct->mlx, g_struct->hero.hero_right);
	mlx_delete_image(g_struct->mlx, g_struct->hero.hero_left);
}
