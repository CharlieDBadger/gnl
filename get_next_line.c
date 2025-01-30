#include "get_next_line.h"

static void update_remainder(char **remainder, int i);
static char	*extract_line(char **remainder);
static char	*read_and_save(int fd, char *remainder, size_t buffer_size);

char	*get_next_line(int fd)
{
	static char	*remainder;
	size_t		buffer_size;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (BUFFER_SIZE > SIZE_MAX - 1)
		buffer_size = SIZE_MAX;
	else
		buffer_size = (size_t)BUFFER_SIZE + 1;
	remainder = read_and_save(fd, remainder, buffer_size);
	if (!remainder)
			return (NULL);
	line = extract_line(&remainder);
	if (!line && remainder)
	{
		free (remainder);
		remainder = NULL;
	}
	return (line);
}

static char	*extract_line(char **remainder)
{
	char	*line;
	int		i;

	if (!*remainder || **remainder == '\0')
		return (NULL);
	i = 0;
	while ((*remainder)[i] && (*remainder)[i] != '\n')
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	line = ft_substr(*remainder, 0 ,i);
	if (!line)
		return (NULL);
	update_remainder(remainder, i);
	return (line);
}

static void update_remainder(char **remainder, int i)
{
	char	*temp;
	
	if ((*remainder)[i] != '\0')
	{
		temp = ft_strdup(*remainder + i);
		free (*remainder);
		*remainder = temp;
	}
	else
	{
		free(*remainder);
		*remainder = NULL;
	}
}

static char	*read_and_save(int fd, char *remainder, size_t buffer_size)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc (buffer_size * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (remainder);
}
/*
#include <stdio.h>

int main(void)
{
	int fd;
	char *line;

	printf("Start\n");
	// Abre el archivo text.txt en modo solo lectura
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}

	// Lee cada línea del archivo usando get_next_line
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Retorno no nulo\n");
		printf("%s", line);
		free(line);
	}

	// Cierra el archivo
	if (close(fd) < 0)
	{
		perror("Error al cerrar el archivo");
		return (1);
	}

	return (0);
}
*/
/*
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=4000 get_next_line.c get_next_line_utils.c get_next_line.h


update_store
process_line
read_and_store
get_next_line
*/
