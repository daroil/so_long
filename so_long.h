/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:26:58 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/17 12:51:55 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "lib/printf/ft_printf.h"
# include "lib/libft/libft.h"

# ifndef STEP
#  define STEP 32
# endif

typedef struct hero_s
{
	mlx_image_t	*hero;
	int			x;
	int			y;
}	t_hero;

typedef struct game_s
{
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
	t_hero			hero;
	char			**map;
	char			**visited;
	int				width;
	int				height;
	int				action_counter;
	int				exit_open;
	int				collected;
	int				all_collectibles;
}	t_game;

void	ft_render_map(t_game *g_struct);
int		hit_an_exit(int x, int y, t_game *g_struct);
void	ft_go_up(mlx_key_data_t keydata, void *param);
void	ft_go_down(mlx_key_data_t keydata, void *param);
void	ft_go_left(mlx_key_data_t keydata, void *param);
void	ft_go_right(mlx_key_data_t keydata, void *param);
void	hook(void *param);
void	ft_render_chars(char *line, int y, t_game *g_struct);
void	ft_create_array(char *path, t_game *g_struct);
int		ft_count_height(char *path);
int		is_at_exit(int x, int y, t_game *g_struct);
void	free_map(t_game *g_struct);
int		check_if_all(t_game *g_struct);
void	ft_initialise_graphics(t_game *g_struct);
int		ft_check_coll_exit(char **visited);
void	ft_get_player_pos(char **map, t_game *g_struct);
int		ft_wrong_symbols(char **map);
int		ft_check_map(char *path, t_game *g_struct);
int		ft_count_collectibles(char **map);
size_t	ft_strlen_nonl(const char *s);
int		ft_is_rectangular(char **map);
int		ft_check_last(char **map, int i);
int		ft_map_closed_walls(char **map);
void	ft_copy_array(char *path, t_game *g_struct);
void	dfs(t_game *g_struct, int y, int x);
void	ft_move_up(t_game *g_struct, int x, int y);
void	ft_move_down(t_game *g_struct, int x, int y);
void	ft_move_left(t_game *g_struct, int x, int y);
void	ft_move_right(t_game *g_struct, int x, int y);
int		player_check(char **map);

#endif
