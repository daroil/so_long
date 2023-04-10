/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_handle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:16:58 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/20 15:45:21 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_enem_pos(t_game *g_struct)
{
	int	i;

	i = 0;
	while (g_struct->enemy_pos[i])
	{
		free (g_struct->enemy_pos[i]);
		i++;
	}
	free (g_struct->enemy_pos);
	g_struct->enemy_pos = NULL;
}

void	ft_get_enemy_pos(char **map, t_game *g_struct, int count)
{
	static int	i = 0;
	static int	j = 0;

	g_struct->enemy_pos[count] = malloc(sizeof(int) * 3);
	if (!g_struct->enemy_pos[count] || !g_struct->enemy_pos[0])
		exit(EXIT_FAILURE);
	g_struct->enemy_pos[count][2] = '\0';
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'D')
			{
				g_struct->enemy_pos[count][0] = j;
				g_struct->enemy_pos[count][1] = i;
				j++;
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

int	ft_count_enemies(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_set_enemy_pos(t_game *g_struct)
{
	int	i;

	g_struct->enemy_count = ft_count_enemies(g_struct->map);
	if (!g_struct->enemy_count)
		return ;
	i = 0;
	g_struct->enemy_pos = malloc (sizeof(int *) * g_struct->enemy_count + 4);
	if (!g_struct->enemy_pos)
		return ;
	while (i < g_struct->enemy_count)
	{
		ft_get_enemy_pos(g_struct->map, g_struct, i);
		i++;
	}
	g_struct->enemy_pos[i] = NULL;
}
