/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:47:32 by brehaili          #+#    #+#             */
/*   Updated: 2014/02/03 16:47:33 by brehaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "rtv1.h"

t_list	*new_list(t_point p, int color)
{
	t_list	*list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_exit("Malloc error\n");
	list->pos = p;
	list->color = color;
	list->next = NULL;
	return (list);
}

t_list	*add_list_list(t_list *head, t_list *list)
{
	t_list	*tmp;

	if (head == NULL)
		return (list);
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list;
		return(head);
	}
}

t_list	*add_list(t_list *head, t_point p, int color)
{
	t_list	*list;
	t_list	*tmp;

	list = new_list(p, color);
	if (head == NULL)
		return (list);
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list;
		return(head);
	}
}