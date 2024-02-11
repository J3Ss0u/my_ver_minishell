/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:40:06 by mel-jira          #+#    #+#             */
/*   Updated: 2024/02/04 20:00:26 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ret_val(t_env *env_list, char *var)
{
	t_env	*tmp;

	tmp = env_list;
	if (!var)
		return (NULL);
	while (tmp)
	{
		if (ft_strcmp(tmp->key, var) == 0)
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}
