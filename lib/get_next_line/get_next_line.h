/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:02:00 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/04 18:10:21 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>

char	*move_next(char *res);
char	*extract_line(char *res);
char	*join_and_free(char *res, char *buffer);
char	*read_file(int fd, char **res);
char	*get_next_line(int fd);
size_t	_strlen(char *s);
void	_bzero(char *s, size_t n);
char	*_calloc(size_t nmnb, size_t size);
char	*_strchr(char *s, char c);
char	*_strjoin(char *s1, char *s2);

#endif
