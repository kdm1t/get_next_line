/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:22:20 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/25 19:59:56 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"

char		*get_string(char **str)
{
	int		i;
	char	*result;
	char	*tofree;

	if (!str || !(*str))
		return (0);
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\n')
		{
			result = ft_strsub(*str, 0, i);
			tofree = *str;
			*str = ft_strjoin(ft_strchr(*str, '\n') + 1, "");
			free(tofree);
			return (result);
		}
		i++;
	}
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	static char		*array[1024];
	char			buff[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;
	char			*tofree;

	if (fd < 0 || !line)
		return (-1);
	if (array[fd] && (*line = get_string(&array[fd])))
		return (1);
	tmp = array[fd];
	while ((ret = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tofree = array[fd];
		if (!(array[fd] = ft_strjoin(array[fd], buff)))
			array[fd] = ft_strjoin(buff, "");
		if (tofree)
			free(tofree);
		tmp = array[fd];
		if (ft_strchr(buff, '\n'))
		{
			*line = get_string(&array[fd]);
			tmp = array[fd];
			return (1);
		}
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && array[fd])
	{
		if (array[fd][0] != '\0')
		{
			*line = ft_strjoin(array[fd], "");
			free(array[fd]);
			array[fd] = NULL;
			return (1);
		}
	}
	tmp = array[fd];
	return (0);
}
