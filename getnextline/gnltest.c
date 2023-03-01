//#include <stdio.h>
//#include <unistd.h>
//#include <fcntl.h> 
#include "get_next_line.c"
#include "get_next_line_utils.c"
//#include <stdlib.h>

int	main(void)
{
	char	*line;
	int		i;
//	int		ret;
	int		fd1;
//	int		fd2;
//	int		fd3;

	fd1 = open("gnltests/test2", O_RDONLY);
	if (fd1 <= 0)
		printf("open 1 failed\n");
/*	fd2 = open("gnltests/test2", O_RDONLY);
	if (fd2 <= 0)
		printf("open 2 failed\n");
	fd3 = open("gnltests/test3", O_RDONLY);
	if (fd3 <= 0)
		printf("open 3 failed\n");*/

	i = 1;
//	ret = 0;
	while (i <= 7)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
/*		line = get_next_line(fd2);
		printf("%s", line);
		line = get_next_line(fd3);
		printf("%s", line);*/
		++i;
	}
	close(fd1);
//	close(fd2);
//	close(fd3);
	return (0);
}
