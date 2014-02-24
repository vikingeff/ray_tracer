/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Coco <Coco@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 12:53:40 by cberteau          #+#    #+#             */
/*   Updated: 2014/01/24 10:23:00 by Coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

static int	find_next(char *str);
static char	*get_next_next(char **str);
static int	len(char *str);
static char	*concat(char  *str, char *buf, int n);

int		get_next_line(int fd, char **line)
{
	char		*ret;
	int			n_read;
	static char	*old;
	static int	i;
	char	buf[BUFF_SIZE];

	while (!(ret = get_next_next(&old)))
	{
		n_read = read(fd, buf, BUFF_SIZE);
		if (!n_read)
			return (0);
		old = concat(old, buf, n_read);
		if (old == NULL)
			return (-1);
	}
	line[i] = ret;
	return (1);
}

static char	*concat(char *old, char *buf, int n)
{
	char	*ret;
	char	*stock;

	if (!(ret = (char*)malloc(len(old) + n + 1)))
	return (NULL);
	stock = ret;
	if (old)
	while (*old)
		*ret++ = *old++;
	*(ret + n) = 0;
	free (old - (ret - stock));
	while (n--)
	*(ret + n) = buf[n];
	return (stock);
}

static char	*get_next_next(char **str)
{
	int		size;
	int		loc;
	char	*ret;
	char	*stock;

	if ((loc = find_next(*str)) == -1)
	return (NULL);
	if (!(ret = (char*)malloc(loc + 1)))
	return (NULL);
	stock = ret;
	while ((ret - stock) < loc)
	*ret++ = *((*str)++);
	*ret = 0;
	size = len(*str);
	if (!(ret = (char*)malloc(size + 1)))
	return (NULL);
	while (**str)
	*ret++ = *(++(*str));
	free(*str - size - loc);
	*str = ret - size;
	return (stock);
}

static int	find_next(char *str)
{
	char	*stock;

	stock = str;
	if (str)
	while (*str)
		if (*str++ == '\n')
		return (str - stock - 1);
	return (-1);
}

static int	len(char *str)
{
	char	*stock;

	if (!str || !*str)
	return (0);
	stock = str;
	while (*str)
	str++;
	return (str - stock);
}
