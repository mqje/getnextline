/*
** get_nex_line.h for get_next_line in /home/maje/delivery/CPE/CPE_2016_getnextline
** 
** Made by maje
** Login   <marin.brunel@epitech.eu>
** 
** Started on  Mon Jan  2 10:04:51 2017 maje
** Last update Sun Jan 15 23:31:37 2017 maje
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE 5

#endif /* READ_SIZE */

char		*get_next_line(const int fd);
char		*fill_buffer(char *buffer, int fd);
static int      my_strlen(char *str);
char		*my_strcat(char *str, char *src);
char		*fill_res(char *buff, char **buffer);

#endif /* GET_NEXT_LINE_H_ */
