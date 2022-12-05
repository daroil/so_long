/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:11:06 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/31 12:25:16 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_to_buf(int fd, char *buf);
int		found_nl(char *buf);
char	*buf_join(char *buf, char *tmp);
size_t	gn_strlen(const char *s);
char	*gn_set_buf(char *buf);
void	gn_free_buf(char **buf);
char	*extract_line(char *buf);
char	*shorten_buf(char *buf);

#endif
