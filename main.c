/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:31:17 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/15 17:42:55 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_all(struct g_structure *g_struct)
{
	if(g_struct->collected == g_struct->all_collectibles)
	{
		int x;
		int y;

		x = g_struct->g_exit_img->instances->x;
		y = g_struct->g_exit_img->instances->y;
		g_struct->g_exit_img = mlx_texture_to_image(g_struct->mlx,
			g_struct->open_exit_texture);
		mlx_image_to_window(g_struct->mlx, g_struct->floor, x, y);
		mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, x, y);
		return(1);
	}
	return(0);
}

int	hit_an_exit(int x, int y,struct g_structure *g_struct)
{
	if (g_struct->hero.x/STEP == x/STEP 
		&& g_struct->hero.y/STEP == y/STEP
		&& g_struct->exit_open == 1)
		return (1);
	return (0);
}

int	is_at_exit(int x, int y, struct g_structure *g_struct)
{
	if (g_struct->hero.x/STEP == x/STEP 
		&& g_struct->hero.y/STEP == y/STEP)
		return (1);
	return (0);
}

void	ft_go_up(mlx_key_data_t keydata, void *param)
{
	struct g_structure *g_struct;
	g_struct = (struct g_structure*)param;
	if (keydata.action == MLX_RELEASE)
	{
		if(g_struct->map[g_struct->hero.y/STEP-1][g_struct->hero.x/STEP] != '1')
		{	
			mlx_image_to_window(g_struct->mlx, g_struct->floor, g_struct->hero.x, g_struct->hero.y);
			if(is_at_exit(g_struct->g_exit_img->instances->x, g_struct->g_exit_img->instances->y, g_struct))
				mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, g_struct->hero.x, g_struct->hero.y);
			
			g_struct->hero.y -= STEP;
			if(g_struct->map[g_struct->hero.y/STEP][g_struct->hero.x/STEP] == 'C')
			{
				g_struct->collected++;
				g_struct->map[g_struct->hero.y/STEP][g_struct->hero.x/STEP] = '0';
				if(check_if_all(g_struct) && g_struct->exit_open==0)
					g_struct->exit_open = 1;
			}
			mlx_image_to_window(g_struct->mlx, g_struct->hero.hero, g_struct->hero.x, g_struct->hero.y);
			ft_printf("Actions taken:%d\n",++g_struct->action_counter);
		}
	}
}

void	ft_go_down(mlx_key_data_t keydata, void *param)
{
	struct g_structure *g_struct;
	g_struct = (struct g_structure*)param;
	if (keydata.action == MLX_RELEASE)
	{
		if(g_struct->map[g_struct->hero.y/STEP+1][g_struct->hero.x/STEP] != '1')
		{	
			mlx_image_to_window(g_struct->mlx, g_struct->floor, g_struct->hero.x, g_struct->hero.y);
			if(is_at_exit(g_struct->g_exit_img->instances->x, g_struct->g_exit_img->instances->y, g_struct))
				mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, g_struct->hero.x, g_struct->hero.y);
			g_struct->hero.y += STEP;
			if(g_struct->map[g_struct->hero.y/STEP][g_struct->hero.x/STEP] == 'C')
			{
				g_struct->collected++;
				g_struct->map[g_struct->hero.y/STEP][g_struct->hero.x/STEP] = '0';
				if(check_if_all(g_struct) && g_struct->exit_open==0)
					g_struct->exit_open = 1;
			}
			mlx_image_to_window(g_struct->mlx, g_struct->hero.hero, g_struct->hero.x, g_struct->hero.y);
			ft_printf("Actions taken:%d\n",++g_struct->action_counter);
		}
	}
}

void	ft_go_left(mlx_key_data_t keydata, void *param)
{
	struct g_structure *g_struct;
	g_struct = (struct g_structure*)param;
	if (keydata.action == MLX_RELEASE)
	{
		if(g_struct->map[g_struct->hero.y/STEP][g_struct->hero.x/STEP-1] != '1')
		{	
			mlx_image_to_window(g_struct->mlx, g_struct->floor, g_struct->hero.x, g_struct->hero.y);
			if(is_at_exit(g_struct->g_exit_img->instances->x, g_struct->g_exit_img->instances->y, g_struct))
				mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, g_struct->hero.x, g_struct->hero.y);
			g_struct->hero.x -= STEP;
			if(g_struct->map[g_struct->hero.y/STEP][g_struct->hero.x/STEP] == 'C')
			{
				
				g_struct->collected++;
				g_struct->map[g_struct->hero.y/STEP][g_struct->hero.x/STEP] = '0';
				if(check_if_all(g_struct) && g_struct->exit_open==0)
					g_struct->exit_open = 1;
			}
			mlx_image_to_window(g_struct->mlx, g_struct->hero.hero, g_struct->hero.x, g_struct->hero.y);
			ft_printf("Actions taken:%d\n",++g_struct->action_counter);
		}
	}
}

void	ft_go_right(mlx_key_data_t keydata, void *param)
{
	struct g_structure *g_struct;
	g_struct = (struct g_structure*)param;
	if (keydata.action == MLX_RELEASE)
	{
		if(g_struct->map[g_struct->hero.y/STEP][g_struct->hero.x/STEP+1] != '1')
		{	
			mlx_image_to_window(g_struct->mlx, g_struct->floor, g_struct->hero.x, g_struct->hero.y);
			if(is_at_exit(g_struct->g_exit_img->instances->x, g_struct->g_exit_img->instances->y, g_struct))
				mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, g_struct->hero.x, g_struct->hero.y);
			
			g_struct->hero.x += STEP;
			if(g_struct->map[g_struct->hero.y/STEP][g_struct->hero.x/STEP] == 'C')
			{
				g_struct->collected++;
				g_struct->map[g_struct->hero.y/STEP][g_struct->hero.x/STEP] = '0';
				if(check_if_all(g_struct) && g_struct->exit_open==0)
					g_struct->exit_open = 1;
			}
			mlx_image_to_window(g_struct->mlx, g_struct->hero.hero, g_struct->hero.x, g_struct->hero.y);
			ft_printf("Actions taken:%d\n",++g_struct->action_counter);
		}
	}
}

void	free_map(struct g_structure *g_struct)
{
	int i;
	i = 0;
	while(g_struct->map[i])
	{
		free(g_struct->map[i]);
		i++;
	}
	free(g_struct->map);
}

void	hook(void *param)
{
	mlx_t	*mlx;
	struct g_structure *g_struct;

	g_struct = (struct g_structure*)param;
	mlx = g_struct->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if ((mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W)))
		mlx_key_hook(mlx, ft_go_up, param);
	if ((mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S)))
		mlx_key_hook(mlx, ft_go_down, param);
	if ((mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A)))
		mlx_key_hook(mlx, ft_go_left, param);
	if ((mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D)))
		mlx_key_hook(mlx, ft_go_right, param);
	if (hit_an_exit(g_struct->g_exit_img->instances->x, g_struct->g_exit_img->instances->y, g_struct))
	{
		write(1, "GAMEOVER", 8);
		mlx_close_window(mlx);
		free_map(g_struct);
	}
}

void	ft_render_chars(char *line, int y, struct g_structure *g_struct)
{
	int x;
	
	x = 0;
	while(*line)
	{
		if(*line == '1')
			mlx_image_to_window(g_struct->mlx, g_struct->crate, x, y);
		if(*line == '0')
			mlx_image_to_window(g_struct->mlx, g_struct->floor, x, y);
		if(*line == 'C')
		{
			mlx_image_to_window(g_struct->mlx, g_struct->floor, x, y);
			mlx_image_to_window(g_struct->mlx, g_struct->collectible, x, y);
		}	
		if(*line == 'P')
		{
			mlx_image_to_window(g_struct->mlx, g_struct->floor, x, y);
			g_struct->hero.x = x;
			g_struct->hero.y = y;
		}
		if(*line == 'E')
		{
			mlx_image_to_window(g_struct->mlx, g_struct->floor, x, y);
			mlx_image_to_window(g_struct->mlx, g_struct->g_exit_img, x, y);
		}	
		x += STEP;
		line++;	
	}
}

void	ft_render_map(struct g_structure *g_struct)
{
	int		y;
	int		x;
	
	x = 0;
	y = 0;
	while(g_struct->map[x])
	{
		if(g_struct->map[x] != NULL)
			ft_render_chars(g_struct->map[x], y, g_struct);	
		y += STEP;
		x++;
	}
	mlx_image_to_window(g_struct->mlx, g_struct->hero.hero, g_struct->hero.x, g_struct->hero.y);
	
}

int	ft_count_height(char *path)
{
	int		fd;
	int		height;
	char	*line;
	
	fd = open(path,'r');
	height = 0;
	line = get_next_line(fd);
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	return(height);	
}

void	ft_create_array(char *path,struct g_structure *g_struct)
{
	int		fd;
	char	*line;
	int		i;
	
	g_struct->height = 0;
	g_struct->map = malloc(sizeof(char*) * ft_count_height(path) + 1);
	fd = open(path,'r');
	
	line = get_next_line(fd);
	g_struct->width = ft_strlen(line);
	if(!g_struct->map)
		free(g_struct->map);
	i = 0;
	while(line)
	{
		if(line != NULL)
			g_struct->map[i] = line;
		line = get_next_line(fd);
		g_struct->height++;
		i++;		
	}
	close(fd);
	g_struct->map[g_struct->height] = NULL;
	// i = 0;
	// while(i < height)
	// {
	// 	ft_printf("%s",g_struct->map[i]);
	// 	i++;
	// }
	
}

void	ft_initialise_graphics(struct g_structure *g_struct)
{
	g_struct->mlx = mlx_init(g_struct->width * STEP - STEP, g_struct->height * STEP, "GAMEBOY", true);
	g_struct->texture = mlx_load_png("/Users/dhendzel/Documents/Pixel_Crawler/Heroes/Knight/Idle/Knight.png");
	g_struct->crate_texture = mlx_load_png("assets/crate.png");
	g_struct->floor_texture = mlx_load_png("assets/floor.png");
	g_struct->exit_texture = mlx_load_png("assets/closed_exit.png");
	g_struct->open_exit_texture = mlx_load_png("assets/open_exit.png");
	g_struct->col_texture = mlx_load_png("assets/coin.png");
	g_struct->crate = mlx_texture_to_image(g_struct->mlx, g_struct->crate_texture);
	g_struct->floor = mlx_texture_to_image(g_struct->mlx, g_struct->floor_texture);
	g_struct->collectible = mlx_texture_to_image(g_struct->mlx, g_struct->col_texture);
	g_struct->hero.hero = mlx_texture_to_image(g_struct->mlx, g_struct->texture);
	g_struct->g_exit_img = mlx_texture_to_image(g_struct->mlx,
			g_struct->exit_texture);
}

size_t	ft_strlen_nonl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}


int	ft_is_rectangular(char **map)
{
	int	i;

	i = 1;
	while(map[i])
	{
		if(ft_strlen_nonl(map[i]) != ft_strlen_nonl(map[i-1]))	
			return(0);
		i++;
	}
	return(1);
}

int	ft_check_last(char **map, int i)
{
	int	j;
	
	j = 0;
	i--;
	while(map[i][j])
	{
		if(map[i][j] != '1' && map[i][j] != '\n')
			return(0);
		j++;
	}
	return(1);
}

int	ft_map_closed_walls(char **map)
{
	int	i;
	int	j;
	int	exit;

	exit = 0;
	i = -1;
	while(map[++i])
	{
		j = 0;
		if(map[i][j] != '1')
				return(0);
		while(map[i][j])
		{
			if(map[i][j] == 'E')
				exit++;
			if(map[0][j] != '1' && map[0][j] != '\n')
				return(0);
			j++;
		}
		if(map[i][j-2] != '1')
				return(0);
	}
	if(exit != 1 || !ft_check_last(map,i))
		return(0);
	return(1);
}

// int	ft_count_arr_height(char **map)
// {
// 	int height;

// 	height = 0;
// 	while(map[height])
// 		height++;
// 	return(height);
// }

// void	free_array(char ***map)
// {
// 	int i;
// 	i = 0;
// 	while(*map[i])
// 	{
// 		free(*map[i]);
// 		i++;
// 	}
// 	free(*map);
// }

// char	**ft_copy_array(char **map)
// {
// 	char	**copy;
// 	int		height;
// 	int		i;
	
// 	height = ft_count_arr_height(map);
// 	copy = malloc(sizeof(char*) * height +1);
// 	if(!copy)
// 	{
// 		free(copy);
// 		return(NULL);
// 	}
// 	i = 0;
// 	while(map[i])
// 	{
// 		// if(map[i] != NULL)	
// 		copy[i] = ft_strdup(map[i]);
// 		i++;		
// 	}
// 	copy[i] = NULL;
// 	return(copy);
// }

void	ft_copy_array(char *path,struct g_structure *g_struct)
{
	int		fd;
	int		width;
	int		height;
	char	*line;
	
	height = 0;
	g_struct->visited = malloc(sizeof(char*) * ft_count_height(path) + 1);
	fd = open(path,'r');
	line = get_next_line(fd);
	width = ft_strlen(line);
	if(!g_struct->visited)
		free(g_struct->visited);
	while(line)
	{
		if(line != NULL)
			g_struct->visited[height] = line;
		line = get_next_line(fd);
		height++;	
	}
	close(fd);
	g_struct->visited[height] = NULL;
}

void	dfs(struct g_structure *g_struct, int y, int x)
{
	g_struct->visited[y][x] = '2';
	if(g_struct->visited[y][x+1] != '2' && g_struct->visited[y][x+1] != '1')
		dfs(g_struct, y, x+1);
	if(g_struct->visited[y+1][x] != '2' && g_struct->visited[y+1][x] != '1')
		dfs(g_struct, y+1, x);
	if(g_struct->visited[y][x-1] != '2' && g_struct->visited[y][x-1] != '1')
		dfs(g_struct, y, x-1);
	if(g_struct->visited[y-1][x] != '2' && g_struct->visited[y-1][x] != '1')
		dfs(g_struct, y-1, x);
}

int	ft_check_coll_exit(char **visited)
{
	int i;
	int j;

	i = 0;
	while(visited[i])
	{
		j = 0;
		while(visited[i][j])
		{
			if(visited[i][j] == 'C' || visited[i][j] == 'E')
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}

void	ft_get_player_pos(char **map,struct g_structure *g_struct)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'P')
			{
				g_struct->hero.x = j;
				g_struct->hero.y = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_wrong_symbols(char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] != 'P' 
			&& map[i][j] != '0' 
			&& map[i][j] != 'E' 
			&& map[i][j] != '\n' 
			&& map[i][j] != 'C' 
			&& map[i][j] != '1')
				return(1);
			j++;
		}
		i++;
	}
	return(0);
}

int	ft_check_map(char *path, struct g_structure *g_struct)
{
	// int i;
	if(ft_wrong_symbols(g_struct->map))
		return(0);
	if(ft_is_rectangular(g_struct->map))
	{
		if(ft_map_closed_walls(g_struct->map))
		{
			ft_copy_array(path, g_struct);
			ft_get_player_pos(g_struct->map, g_struct);
			dfs(g_struct,g_struct->hero.y,g_struct->hero.x);
			if(ft_check_coll_exit(g_struct->visited))	
				return(1);
		// i = 0;
		// while(i < 14)
		// {
		// 	ft_printf("%s",g_struct->visited[i]);
		// 	i++;
		// }
		// ft_printf("y:%d, x:%d\n",g_struct->hero.y,g_struct->hero.x);
		// i = 0;
		// while(i < 14)
		// {
		// 	ft_printf("%s",g_struct->visited[i]);
		// 	i++;
		// }
		}
	}
	return(0);
}

int	ft_count_collectibles(char **map)
{
	int i;
	int j;
	int	count;

	i = 0;
	count = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return(count);
}

int32_t	main(int argc, char **argv)
{
	struct g_structure g_struct;
	// int i;
	if(argc != 2)
	{
		ft_printf("Incorrect input, my dear, try again!\n");
		ft_printf("Correct input is ./game 'relative map path'\n");
		return(EXIT_FAILURE);
	}
	ft_create_array(argv[1], &g_struct);
	if(ft_check_map(argv[1], &g_struct))
	{
		g_struct.action_counter = 0;
		g_struct.exit_open = 0;
		g_struct.all_collectibles = ft_count_collectibles(g_struct.map);
		g_struct.collected = 0;
		g_struct.mlx = NULL;
		ft_initialise_graphics(&g_struct);
		if (!g_struct.mlx)
			exit(EXIT_FAILURE);
		ft_render_map(&g_struct);
		mlx_loop_hook(g_struct.mlx, &hook, &g_struct);
		mlx_loop(g_struct.mlx);
		mlx_terminate(g_struct.mlx);
	}
	else
	{
		ft_printf("Error\nThe map is invalid, my dear, try another one!\n");
	}	
	// g_struct->all_collectibles = ft_count_collectibles(g_struct);
	// i = 0;
	// while(i < 10)
	// {
	// 	ft_printf("%s",g_struct.map[i]);
	// 	i++;
	// }
	// ft_initialise_map();
	system("leaks game");
	return (EXIT_SUCCESS);
}
