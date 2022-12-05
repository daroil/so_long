/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:27:16 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/25 23:43:55 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

trans_list	*ft_lstnew(void *content)
{
	trans_list	*node;

	node = (trans_list *) malloc(sizeof(trans_list));
	if (!node)
		return (NULL);
	node->content = (void *)content;
	node->next = NULL;
	return (node);
}
