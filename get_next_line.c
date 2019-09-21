/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:22:20 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/21 16:38:50 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	static char	*array[7777];
	char		buff[BUFF_SIZE + 1];
	int			i;
	int			ret;

	if (fd < 0)
		return (0);
	while ((ret = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		i = 0;
		while (i < ret)
		{
			buff[ret] = '\0';
			if (buff[i] == '\n')
			{
				ft_strjoin(array[fd], ft_strsub(buff, 0, i));
				*line = array[fd];
			}
			i++;
		}
	}
	return (1);
}


int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		return (0);
	char *str;
	fd = open(argv[1], O_RDONLY | O_CREAT);
	get_next_line(fd, &str);
	return (0);
}
