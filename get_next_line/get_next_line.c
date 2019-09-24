/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:22:20 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/24 15:57:09 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	static char	*array[250];
	char		buff[BUFF_SIZE + 1];
	int			i;
	int			ret;
	char		*tmp;

	if (fd < 0)
		return (0);
	tmp = array[fd];
	while ((ret = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		i = 0;
		buff[ret] = '\0';
		while (i < ret)
		{
			i++;	
		}
	}
	return (1);
}

int main(void)
{
	int fd;
	char *str;
	fd = open("filetest.txt", O_RDONLY | O_CREAT);
	get_next_line(fd, &str);
	return (0);
}
