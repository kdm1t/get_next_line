/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:50:39 by mwilbur           #+#    #+#             */
/*   Updated: 2019/10/07 18:10:08 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int     get_next_line(const int fd, char **line)
{
    static t_list *list;
    t_list *current;
    char buff[BUFF_SIZE + 1];
    int ret;
    // int i;
    
    if (fd < 0 || !line)
        return (-1);
    current = get_fd(&list, fd);
    if (!current)
        return (-1);
    while ((ret = read(fd,buff,BUFF_SIZE)) > 0)
    {
        buff[ret] = '\0';
        current->content = ft_strjoin(current->content, buff);
        if (!(current->content))
            return (-1);
        if (ft_strchr(buff, '\n'))
            break;
    }
    if (ret < BUFF_SIZE && !ft_strlen(current->content))
        return (0);
    // i = 
    // if (i < ft_strlen(current->content))
    //     current->content += (i + 1);
    // else
        ft_strclr(current->content);
    return (1);
}

int main()
{
    
    return (0);
}