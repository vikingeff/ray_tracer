/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 03:17:17 by jshkurti          #+#    #+#             */
/*   Updated: 2013/12/17 17:33:19 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

#define BUFF_SIZE 32

int		no_leak_exit(char *memory, int ret)
{
	free(memory);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t		sz;
	static char	*mem;
	char		*tmp;
	char		*endl;
	char		buff[BUFF_SIZE + 1] = {'\0'};

	if (line && mem && (tmp = mem) && (endl = ft_strchr(mem, '\n')))
	{
		if (!(*line = ft_strsub(mem, 0, endl - mem))
			|| !(mem = ft_strsub(endl + 1, 0, ft_strlen(endl + 1))))
			return (no_leak_exit(mem, -1));
		free(tmp);
		return (1);
	}
	else if ((sz = 1) && line && (sz = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((!mem && !(mem = ft_strnew(0))) || ((tmp = mem) && 0)
			|| !(mem = ft_strjoin(mem, buff)))
			return (no_leak_exit(mem, -1));
		free(tmp);
		return (get_next_line(fd, line));
	}
	if (sz == -1 || !line || !mem || ((*line = mem) && (mem = NULL)))
		return (no_leak_exit(mem, sz = (sz == -1 || !line) ? -1 : 0));
	return (no_leak_exit(tmp = **line ? NULL : *line, sz = **line ? 1 : 0));
}
