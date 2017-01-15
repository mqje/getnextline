/*
** get_nex_line.c for get_next_line in /home/maje/delivery/CPE/CPE_2016_getnextline
** 
** Made by maje
** Login   <marin.brunel@epitech.eu>
** 
** Started on  Wed Dec 21 16:18:40 2016 maje
** Last update Sun Jan 15 14:32:18 2017 maje
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}

char	*my_strcat(char *str, char *src)
{
  int	i;
  int	j;
  char	*res;

  if ((res = malloc(sizeof(char) * (my_strlen(src) + my_strlen(str)))) == NULL)
    return (NULL);
  i = -1;
  j = -1;
  while (str[++i])
    res[++j] = str[i];
  i = -1;
  while (src[++i])
    res[++j] = str[i];
  return (res);
}

void	fill_buffer(char **str, const int fd)
{
  int	i;
  char	buffer[READ_SIZE];

  i = 0;
  if ((*str = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return ;
  while (read(fd, buffer, READ_SIZE) != 0)
    {
      *str[i] = buffer[i];
      i++;
    }
}

char	*get_next_line(const int fd)
{
  static char	*buffer;
  char		*buff;

  if ((buffer = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  if ((buff = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  if (buffer == NULL)
    {
      fill_buffer(&buff, fd);
    }
  buffer = my_strcat(buff, buffer);
  return (buffer);
}

void	main(int ac, char **av)
{
  int  fd;

  fd = open(av[1], O_RDONLY);
  close(fd);
}
