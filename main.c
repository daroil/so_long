/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:31:17 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/15 23:34:59 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(void *param)
{
	mlx_t	*mlx;
	t_game	*g_struct;

	g_struct = (t_game *) param;
	mlx = g_struct->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if ((mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W)))
		mlx_key_hook(mlx, ft_go_up, param);
	if ((mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S)))
		mlx_key_hook(mlx, ft_go_down, param);
	if ((mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A)))
		mlx_key_hook(mlx, ft_go_left, param);
	if ((mlx_is_key_down(mlx, MLX_KEY_RIGHT)
			|| mlx_is_key_down(mlx, MLX_KEY_D)))
		mlx_key_hook(mlx, ft_go_right, param);
	if (hit_an_exit(g_struct->g_exit_img->instances->x,
			g_struct->g_exit_img->instances->y, g_struct))
	{
		write(1, "GAMEOVER", 8);
		mlx_close_window(mlx);
		free_map(g_struct);
	}
}

void	dfs(t_game *g_struct, int y, int x)
{
	g_struct->visited[y][x] = '2';
	if (g_struct->visited[y][x + 1] != '2'
		&& g_struct->visited[y][x + 1] != '1')
		dfs(g_struct, y, x + 1);
	if (g_struct->visited[y + 1][x] != '2'
		&& g_struct->visited[y + 1][x] != '1')
		dfs(g_struct, y + 1, x);
	if (g_struct->visited[y][x - 1] != '2'
		&& g_struct->visited[y][x - 1] != '1')
		dfs(g_struct, y, x - 1);
	if (g_struct->visited[y - 1][x] != '2'
		&& g_struct->visited[y - 1][x] != '1')
		dfs(g_struct, y - 1, x);
}

void	set_structure(t_game *g_struct)
{
		g_struct->action_counter = 0;
		g_struct->exit_open = 0;
		g_struct->all_collectibles = ft_count_collectibles(g_struct->map);
		g_struct->collected = 0;
		g_struct->mlx = NULL;
}

int32_t	main(int argc, char **argv)
{
	t_game	g_struct;

	if (argc != 2)
	{
		ft_printf("Incorrect input, my dear, try again!\n");
		ft_printf("Correct input is ./game 'relative map path'\n");
		return (EXIT_FAILURE);
	}
	ft_create_array(argv[1], &g_struct);
	if (ft_check_map(argv[1], &g_struct))
	{
		set_structure(&g_struct);
		ft_initialise_graphics(&g_struct);
		if (!g_struct.mlx)
			exit(EXIT_FAILURE);
		ft_render_map(&g_struct);
		mlx_loop_hook(g_struct.mlx, &hook, &g_struct);
		mlx_loop(g_struct.mlx);
		mlx_terminate(g_struct.mlx);
	}
	else
		ft_printf("Error\nThe map is invalid, my dear, try another one!\n");
	system("leaks game");
	return (EXIT_SUCCESS);
}
