/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 00:17:17 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/28 00:20:31 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *list;
	t_list *del_list;

	if (!lst || !del)
		return ;
	list = *lst;
	while (list)
	{
		del_list = list;
		list = list->next;
		del(del_list->content);
		free(del_list);
	}
}