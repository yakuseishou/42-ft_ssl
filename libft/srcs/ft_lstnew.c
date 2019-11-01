/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:33:38 by kchen2            #+#    #+#             */
/*   Updated: 2019/02/21 16:06:58 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nwls;

	if (!(nwls = (t_list *)malloc(sizeof(*nwls))))
		return (0);
	if (!content)
	{
		nwls->content = NULL;
		nwls->content_size = 0;
	}
	else
	{
		nwls->content = malloc(content_size);
		if (!nwls->content)
			return (0);
		ft_memcpy(nwls->content, content, content_size);
		nwls->content_size = content_size;
	}
	nwls->next = NULL;
	return (nwls);
}
