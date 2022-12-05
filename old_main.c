/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:31:17 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/05 16:22:33 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1920
#define HEIGHT 1080

mlx_image_t	*g_img;
mlx_image_t	*g_exit_img;

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
	if (g_img->instances[0].x <= x 
		&& g_img->instances[0].x >= x - 14  
		&& g_img->instances[0].y <= y
		&& g_img->instances[0].y >= y - 21)
		return (1);
	return (0);
}

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if ((mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		&& g_img->instances[0].y > 200)
		g_img->instances[0].y -= 5;
	if ((mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		&& g_img->instances[0].y < 680)
		g_img->instances[0].y += 5;
	if ((mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		&& g_img->instances[0].x > 200)
		g_img->instances[0].x -= 5;
	if ((mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		&& g_img->instances[0].x < 410)
		g_img->instances[0].x += 5;
	if (hit_an_exit(g_exit_img->instances[0].x, g_exit_img->instances[0].y))
	{
		write(1, "GAMEOVER", 8);
		mlx_close_window(mlx);
	}
}



int32_t	main()
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_texture_t	*crate_texture;
	mlx_texture_t	*exit_texture;
	int				x;
	int				y;
	mlx_image_t		*crate;

	mlx = mlx_init(WIDTH, HEIGHT, "GAMEBOY", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	texture = mlx_load_png("/Users/dhendzel/Documents/Pixel_Crawler/Heroes/Knight/Idle/Knight.png");
	crate_texture = mlx_load_png("/Users/dhendzel/Documents/Pixel_Crawler/Environment/Dungeon_Prison/Assets/crate.png");
	exit_texture = mlx_load_png("/Users/dhendzel/Documents/Pixel_Crawler/Environment/Dungeon_Prison/Assets/exit.png");
	g_img = mlx_texture_to_image(mlx, texture);
	crate = mlx_texture_to_image(mlx, crate_texture);
	g_exit_img = mlx_texture_to_image(mlx, exit_texture);
	mlx_image_to_window(mlx, g_img, 300, 300);
	y = 200;
	while (y <= 680)
	{
		x = 200;
		mlx_image_to_window(mlx, crate, x, y);
		while (x <= 410)
		{
			if (y == 200 || y == 680)
				mlx_image_to_window(mlx, crate, x, y);
			x += 16;
		}
		mlx_image_to_window(mlx, crate, x, y);
		y += 24;
	}
	mlx_image_to_window(mlx, g_exit_img, 350, 420);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}


		