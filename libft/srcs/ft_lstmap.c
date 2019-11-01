/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:30:52 by kchen2            #+#    #+#             */
/*   Updated: 2019/02/21 14:12:55 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nls;
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = f(lst);
	nls = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(lst)))
		{
			free(tmp->next);
			return (0);
		}
		tmp = tmp->next;
	}
	return (nls);
}
