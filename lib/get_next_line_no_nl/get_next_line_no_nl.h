/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_no_nl.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:02:00 by itakumi           #+#    #+#             */
/*   Updated: 2026/01/06 16:54:35 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_NO_NL_H
# define GET_NEXT_LINE_NO_NL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>

char	*get_next_line_no_nl(int fd);
size_t	__strlen(char *s);
void	__bzero(char *s, size_t n);
char	*__calloc(size_t nmnb, size_t size);
char	*__strchr(char *s, char c);
char	*__strjoin(char *s1, char *s2);

#endif
