/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:50:39 by mwilbur           #+#    #+#             */
/*   Updated: 2019/10/15 12:18:31 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

t_list  *get_fd(t_list **ptr, int fd)
{
    while (*ptr)
    {
        if ((int)(*ptr)->content_size == fd)
            return (*ptr);
        *ptr = (*ptr)->next;
    }
    *ptr = ft_lstnew("\0", fd);
    ft_lstadd(ptr, *ptr);
    return (*ptr);
}

int     ft_strcpy_befch(char **first, char *second, char c)
{
    int i;
    int counter;
    char *tmp;

     i = 0;
     counter = 0;
     while (second[i])
     {
         if (second[i] == c)
            break;
        i++;
     }
     *first = ft_strnew(i);
     tmp = ft_strnew(0);
    if (!(*first) || !(tmp))
        return (0);
    while (second[counter] && counter < i)
    {
        *tmp = second[counter];
        *first = ft_strjoin(*first, tmp);
        if (!(*first))
            return (0);
        counter++;
    }
    return (i);
}

int     ft_result(int ret, char **line, t_list *current)
{
    if (ret < BUFF_SIZE && !ft_strlen(current->content))
        return (0);
    int i;

    i = 0;
    i = ft_strcpy_befch(line, current->content, '\n');
    if (i < (int)ft_strlen(current->content))
        current->content += (i + 1);
    else
        ft_strclr(current->content);
    return (1);

}

int     get_next_line(const int fd, char **line)
{
    static t_list   *list;
    t_list          *current;
    char            buff[BUFF_SIZE + 1];
    int             ret;

    if (fd < 0 || !line)
        return (-1);
    current = get_fd(&list, fd);
    if (!current)
        return (-1);
    *line = ft_strnew(0);
    if (!(*line))
        return (-1);
    while ((ret = read(fd,buff,BUFF_SIZE)))
    {
        buff[ret] = '\0';
        current->content = ft_strjoin(current->content, buff);
        if (!(current->content))
            return (-1);
        if (ft_strchr(buff, '\n'))
            return (ft_result(ret, line, current));
    }
    return (ft_result(ret, &(*line), current));
}

// int     main(void)
// {
//     char *line;
//     int out;
//     int p[2];
//     int fd;

//     fd = 1;
//     out = dup(fd);
//     pipe(p);

//     dup2(p[1], fd);
//     write(fd, "aaa\nbbb\nccc\nddd\n", 16);
//     dup2(out, fd);
//     close(p[1]);
//     get_next_line(p[0], &line);
//     printf("aaa = %s\n", line);
//     get_next_line(p[0], &line);
//     printf("bbb = %s\n", line);
//     get_next_line(p[0], &line);
//     printf("ccc = %s\n", line);
//     get_next_line(p[0], &line);
//     printf("ddd = %s\n", line);
// }
