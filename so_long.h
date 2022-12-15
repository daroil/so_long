/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:26:58 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/15 16:59:12 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "ft_printf/ft_printf.h"
#include "libft_2/libft.h"

#ifndef STEP
int STEP = 32;
#endif

typedef struct tile_s
{
	int	x;
	int y;
} tile_t;

typedef struct hero_s
{
	mlx_image_t	*hero;
	int	x;
	int y;
	tile_t		hero_tile;
} hero_t;

struct g_structure
{
	// mlx_image_t		*hero;
	mlx_image_t		*g_exit_img;
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_texture_t	*crate_texture;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*col_texture;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*open_exit_texture;
	mlx_image_t		*crate;
	mlx_image_t		*floor;
	mlx_image_t		*collectible;
	// int				hero_x;
	// int				hero_y;
	hero_t			hero;
	char			**map;
	char			**visited;
	int				width;
	int				height;
	int				action_counter;
	int				exit_open;
	int				collected;
	int				all_collectibles;
};

void	ft_render_map(struct g_structure *g_struct);
int		hit_an_exit(int x, int y,struct g_structure *g_struct);
void	ft_go_up(mlx_key_data_t keydata, void *param);
void	ft_go_down(mlx_key_data_t keydata, void *param);
void	ft_go_left(mlx_key_data_t keydata, void *param);
void	ft_go_right(mlx_key_data_t keydata, void *param);
void	hook(void *param);
void	ft_render_chars(char *line, int y,struct g_structure *g_struct);
void	ft_create_array(char *path,struct g_structure *g_struct);

#endif
