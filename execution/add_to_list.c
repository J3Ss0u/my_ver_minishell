/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:40:37 by sacharai          #+#    #+#             */
/*   Updated: 2024/02/11 19:32:52 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	add_to_list(t_ex **allcmd)
{
	int		i;
	char	*equal_sign;
	t_env	*new;
	t_env	*tmp;

	i = 2;
	new = (t_env *)malloc(sizeof(t_env));
	tmp = new;
	while (allcmd[i])
	{
		equal_sign = ft_strchr(allcmd[i], '=');
		new->key = ft_substr(allcmd[i], 0, get_index(allcmd[i], '='));
		new->value = equal_sign + 1;
		new = new->next;
		i++;
	}
	return (*tmp);
}
