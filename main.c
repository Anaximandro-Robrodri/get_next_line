#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int main()
{
	int 	fd;
	char	*line;
//	int		i = 0;
	fd = open("test.txt", O_RDONLY);
//	printf("soy fd del main: %d\n", fd);
//	while (i < 6)
//	{
		get_next_line(fd, &line);
//		i++;
//	}
	close(fd);
}
