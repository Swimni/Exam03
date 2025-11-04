/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:28:27 by nguinot-          #+#    #+#             */
/*   Updated: 2025/10/24 10:40:19 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gnl.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i = 0;

	while (s[i])
		i++;
	dup = (char *)malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *gnl(int fd)
{
	char		line[10000];
	static char	buffer[BUFFER_SIZE];
	static int	readed = 0;
	static int	j = 0;
	int			i = 0;

	if (fd < 0 | BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if(j >= readed)
		{
			readed = read(fd, buffer, BUFFER_SIZE);
			j = 0;
			if (readed == 0)
				break;
		}
		line[i++] = buffer[j++];
		if (line[i - j] == '\n')
			break;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return(ft_strdup(line));
}

int main()
{
	int		fd;
	char	*line;
	
	fd = open("subject.txt", O_RDONLY);
	line = gnl(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = gnl(fd);
	}
	close(fd);
	return (0);
}