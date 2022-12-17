/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:11:15 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/09 18:36:03 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = read_to_buf(fd, buf);
	if (!buf)
		return (NULL);
	if (buf[0] == '\0')
	{
		gn_free_buf(&buf);
		return (NULL);
	}
	line = extract_line(buf);
	buf = shorten_buf(buf);
	return (line);
}

char	*shorten_buf(char *buf)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		gn_free_buf(&buf);
		return (NULL);
	}
	tmp = malloc(gn_strlen(buf) - i + 1);
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (buf[i] != '\0')
		tmp[j++] = buf[i++];
	tmp[j] = '\0';
	gn_free_buf(&buf);
	return (tmp);
}

char	*extract_line(char *buf)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!buf)
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
		tmp = malloc(i + 1);
	else if (buf[i] == '\n')
		tmp = malloc(i + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		tmp[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	return (tmp);
}

char	*read_to_buf(int fd, char *buf)
{
	char	*tmp;
	int		start_again;
	int		bytes;

	bytes = 0;
	start_again = 1;
	tmp = malloc (BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (start_again == 1)
	{
		if (found_nl(buf))
			break ;
		bytes = read(fd, &tmp[0], BUFFER_SIZE);
		tmp[bytes] = '\0';
		buf = buf_join(buf, tmp);
		if (bytes < BUFFER_SIZE)
			start_again = 0;
	}
	free(tmp);
	tmp = NULL;
	return (buf);
}
