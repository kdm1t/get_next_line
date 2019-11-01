/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:39:15 by mwilbur           #+#    #+#             */
/*   Updated: 2019/11/01 17:54:43 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_str(char **str, char **line, int ret)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (!ret && (!(*str) || !(*str)[0]))
		return (0);
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	*line = ft_strsub(*str, 0, i);
	if ((*str)[i] == '\n')
		tmp = ft_strdup(ft_strchr(*str, '\n') + 1);
	free(*str);
	*str = tmp;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*str[10240];
	char		*ptr;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(0);
		ptr = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = ptr;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret == -1)
		return (-1);
	return (get_str(&str[fd], line, ret));
}
