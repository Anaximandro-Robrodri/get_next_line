#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
int	ft_returns(int n_bytes, char **save, int fd)
{
	if (n_bytes == 0 && save[fd] == '\0')
		return (0);
	else if (n_bytes < 0)
		return (-1);
	else
		return (1);
}

int	get_next_line(int fd, char **line)
{
	char			*aux;
	char			buffer[BUFFER_SIZE + 1];
	static char		*save[FD_SETSIZE];
	int				n_bytes;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	n_bytes = read(fd, buffer, BUFFER_SIZE);
	while (n_bytes > 0)
	{
		buffer[n_bytes] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buffer);
		else
			save[fd] = ft_strjoin(save[fd], buffer);
		if (ft_strchr(save[fd], '\n'))
			break ;
		n_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	aux = ft_strchr(save[fd], '\n');
	*line = ft_substr(save[fd], 0, (aux - save[fd]));
	save[fd] = ++aux;
	return (ft_returns(n_bytes, &save[fd], fd));
}
