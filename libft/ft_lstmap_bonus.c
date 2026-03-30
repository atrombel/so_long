/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:45:07 by atrombel          #+#    #+#             */
/*   Updated: 2025/10/16 14:03:14 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*nobj;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	nobj = NULL;
	while (lst)
	{
		nobj = ft_lstnew((f(lst->content)));
		if (!nobj)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, nobj);
		lst = lst->next;
	}
	return (new);
}
