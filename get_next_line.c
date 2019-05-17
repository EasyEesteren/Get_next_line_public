/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 12:32:03 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/15 12:59:29 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_copy(char **line, char *content, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (content[i] && content[i] != c)
		i++;
	*line = ft_strndup(content, i);
	if (!(*line))
		return (0);
	return (i);
}

t_list	*get_list(int fd, t_list **harris)
{
	t_list	*tmp;

	if (!harris)
		return (NULL);
	tmp = *harris;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(harris, tmp);
	return (tmp);
}

int		my_read(const int fd, char **content)
{
	int		read_res;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	while ((read_res = read(fd, buf, BUFF_SIZE)))
	{
		buf[read_res] = '\0';
		tmp = *content;
		*content = ft_strjoin(*content, buf);
		if (!(*content))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, ENDL))
			break ;
	}
	return (read_res);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	t_list			*list;
	static	t_list	*head;
	char			*tmp;
	size_t			read_res;

	if (0 > fd || line == NULL || (read(fd, buf, 0)) < 0)
		return (-1);
	list = get_list(fd, &head);
	if (!list)
		return (-1);
	tmp = list->content;
	read_res = my_read(fd, &tmp);
	list->content = tmp;
	if (!read_res && !*tmp)
		return (0);
	read_res = line_copy(line, list->content, ENDL);
	if (tmp[read_res] != '\0')
	{
		list->content = ft_strdup(&tmp[read_res + 1]);
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}
