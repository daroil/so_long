/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:18:00 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/21 19:21:01 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gn_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gn_set_buf(char *buf)
{
	buf = malloc (1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	return (buf);
}

void	gn_free_buf(char **buf)
{
	free(*buf);
	*buf = NULL;
}

char	*buf_join(char *buf, char *tmp)
{
	size_t	i;
	size_t	j;
	char	*s_joined;

	if (!buf)
		buf = gn_set_buf(buf);
	s_joined = malloc(gn_strlen(buf) + gn_strlen(tmp) + 1);
	if (!s_joined)
		return (NULL);
	i = 0;
	while (buf[i] != '\0')
	{
		s_joined[i] = buf[i];
		i++;
	}
	j = 0;
	while (tmp[j] != '\0')
		s_joined[i++] = tmp[j++];
	s_joined[i] = '\0';
	gn_free_buf(&buf);
	return (s_joined);
}

int	found_nl(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
