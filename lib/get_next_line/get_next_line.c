/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 07:55:39 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/19 10:37:17 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_next(char *stuck)
{
	size_t	i;
	size_t	j;
	char	*next;

	i = 0;
	while (stuck[i] && stuck[i] != '\n')
		i++;
	if (!stuck[i])
	{
		free(stuck);
		return (stuck = NULL, NULL);
	}
	i++;
	next = ft_calloc((ft_strlen(stuck) - i + 1), sizeof(char));
	if (!next)
	{
		free(stuck);
		return (stuck = NULL, NULL);
	}
	j = 0;
	while (stuck[i])
		next[j++] = stuck[i++];
	next[j] = '\0';
	free(stuck);
	return (stuck = NULL, next);
}

char	*extract_line(char *stuck)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!stuck[i])
		return (NULL);
	while (stuck[i] && stuck[i] != '\n')
		i++;
	if (stuck[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stuck[i] && stuck[i] != '\n')
	{
		line[i] = stuck[i];
		i++;
	}
	if (stuck[i] && stuck[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*join_and_free(char *stuck, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stuck, buffer);
	free(stuck);
	stuck = NULL;
	return (tmp);
}

char	*read_file(int fd, char **stuck)
{
	char		*buffer;
	ssize_t		read_bytes;

	if (!*stuck)
	{
		*stuck = ft_calloc(1, 1);
		if (!*stuck)
			return (NULL);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(*stuck), *stuck = NULL, free(buffer), NULL);
		buffer[read_bytes] = 0;
		*stuck = join_and_free(*stuck, buffer);
		if (!*stuck)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (*stuck);
}

char	*get_next_line(int fd)
{
	static char	*stuck = NULL;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_file(fd, &stuck);
	if (!tmp || !*tmp)
	{
		free(stuck);
		stuck = NULL;
		return (NULL);
	}
	line = extract_line(tmp);
	if (!line)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	stuck = move_next(stuck);
	return (line);
}
// #include <fcntl.h>
// int	main(void)
// {
// 	int	count = 0;
// 	int fd = open("test.txt", O_RDONLY);
// 	fd = 0;
// 	char *res = get_next_line(fd);
// 	while (res > 0)
// 	{
// 		printf("[%d]:%s", count, res);
// 		count++;
// 		free(res);
// 		res = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
