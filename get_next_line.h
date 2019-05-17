/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 12:35:16 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/15 13:18:44 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define BUFF_SIZE 4000
# define ENDL		'\n'

int		get_next_line(const int fd, char **line);

#endif
