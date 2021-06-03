#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	char			*aux;
	static char		*save[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = calloc (BUFFER_SIZE + 1, sizeof(char));
	while (read(fd, buffer, BUFFER_SIZE))
	{
		if (!save[fd])
		{
			printf("soy el buffer bitch: \n%s\n", buffer);
			aux = strchr(buffer, '\n');
			save[fd] = ft_substr(buffer, 0, (aux - buffer));
			line[fd] = save[fd];
		}		
		else
		{
			printf("%s\n", save[fd]);
		}
		printf("Soy FD\n%d\n", fd);
		printf("Soy el save: \n%s\n", save[fd]);
		printf("Soy el line: \n%s\n", line[fd]);
		if (strchr(buffer, '\n'))
			break ;
	}
	return (0);
}
