/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:59:37 by sacharai          #+#    #+#             */
/*   Updated: 2024/02/10 15:03:48 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lstsize(t_exec *lst)
{
	int		count;
	t_exec	*tmp;

	count = 0;
	tmp = (t_exec *)lst;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}