/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:31:17 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/06 15:44:45 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct g_structure
{
	mlx_image_t		*hero;
	mlx_image_t		*g_exit_img;
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_texture_t	*crate_texture;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*exit_texture;
	mlx_image_t		*crate;
	mlx_image_t		*floor;
	int				hero_x;
	int				hero_y;
};

struct g_structure g_struct;

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*s1;

	if (!s)
		return (NULL);
	s1 = (unsigned char *) s;
	i = 0;
	while (i != len)
	{
		s1[i] = c;
		i++;
	}
	return (s1);
}

// int	hit_any_obstacle(int *x, int *y)
// {
// 	putstr(x);
// 	putstr(y);
// 	return(0);	
// }

int	hit_an_exit(int x, int y)
{
	if (g_struct.hero->instances->x <= x 
		&& g_struct.hero->instances->x >= x - 14  
		&& g_struct.hero->instances->y <= y
		&& g_struct.hero->instances->y >= y - 21)
		return (1);
	return (0);
}

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if ((mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W)))
		g_struct.hero->instances->y -= 5;
	if ((mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S)))
		g_struct.hero->instances->y += 5;
	if ((mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A)))
		g_struct.hero->instances->x -= 5;
	if ((mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D)))
		g_struct.hero->instances->x += 5;
	if (g_struct.hero->instances->x == g_struct.crate->instances->x && g_struct.hero->instances->y == g_struct.crate->instances->y)
		g_struct.hero->instances->x -= 5;
		
	if (hit_an_exit(g_struct.g_exit_img->instances->x, g_struct.g_exit_img->instances->y))
	{
		write(1, "GAMEOVER", 8);
		mlx_close_window(mlx);
	}
}

void	ft_initialise_map(void)
{
	int	fd;
	int width;
	int height;
	char *line;
	fd = open("maps/map1.ber",'r');
	line = get_next_line(fd);
	
	ft_printf("%s",line);
	width = ft_strlen(line) * 32;
	height = 0;
	while(line)
	{
		line = get_next_line(fd);
		ft_printf("%s",line);
		height++;		
	}
	g_struct.mlx = mlx_init(width - 32, height * 32, "GAMEBOY", true);
	close(fd);
}

void	ft_render_chars(char *line, int y)
{
	int x;
	
	x = 0;
	while(*line)
	{
		if(*line == '1')
			mlx_image_to_window(g_struct.mlx, g_struct.crate, x, y);
		if(*line == '0')
			mlx_image_to_window(g_struct.mlx, g_struct.floor, x, y);
		if(*line == 'P')
		{
			mlx_image_to_window(g_struct.mlx, g_struct.floor, x, y);
			g_struct.hero_x = x;
			g_struct.hero_y = y;
		}	
		if(*line == 'E')
		{
			mlx_image_to_window(g_struct.mlx, g_struct.floor, x, y);
			mlx_image_to_window(g_struct.mlx, g_struct.g_exit_img, x, y);
		}	
		x += 32;
		line++;	
	}
}

void	ft_render_map(void)
{
	int		fd;
	char	*line;
	int		y;
	
	y = 0;
	fd = open("maps/map1.ber",'r');
	line = get_next_line(fd);
	if(line != NULL)
		ft_render_chars(line, y);
	ft_printf("%s",line);
	while(line)
	{
		line = get_next_line(fd);
		y += 32;
		if(line != NULL)
			ft_render_chars(line, y);
		ft_printf("%s",line);		
	}
	mlx_image_to_window(g_struct.mlx, g_struct.hero, g_struct.hero_x, g_struct.hero_y);
	close(fd);
}


int32_t	main()
{
	g_struct.texture = mlx_load_png("/Users/dhendzel/Documents/Pixel_Crawler/Heroes/Knight/Idle/Knight.png");
	g_struct.crate_texture = mlx_load_png("assets/crate.png");
	g_struct.floor_texture = mlx_load_png("assets/floor.png");
	g_struct.exit_texture = mlx_load_png("/Users/dhendzel/Documents/Pixel_Crawler/Environment/Dungeon_Prison/Assets/exit.png");
	g_struct.mlx = NULL;
	ft_initialise_map();
	if (!g_struct.mlx)
		exit(EXIT_FAILURE);
	g_struct.crate = mlx_texture_to_image(g_struct.mlx, g_struct.crate_texture);
	g_struct.floor = mlx_texture_to_image(g_struct.mlx, g_struct.floor_texture);
	g_struct.hero = mlx_texture_to_image(g_struct.mlx, g_struct.texture);
	g_struct.g_exit_img = mlx_texture_to_image(g_struct.mlx, g_struct.exit_texture);
	ft_render_map();
	mlx_loop_hook(g_struct.mlx, &hook, g_struct.mlx);
	mlx_loop(g_struct.mlx);
	mlx_terminate(g_struct.mlx);
	return (EXIT_SUCCESS);
}


		