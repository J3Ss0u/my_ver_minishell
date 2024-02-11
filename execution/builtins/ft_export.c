/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:07:31 by sacharai          #+#    #+#             */
/*   Updated: 2024/02/11 19:33:54 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_export(t_env *exp_list, t_ex **allcmd)
{
	int		i;
	t_env	*new;

	i = 2;
	if (allcmd[1])
	{
		pars_args(*allcmd, "export");
		*new = add_to_list(allcmd);

	}
	else if (!allcmd[2])
	{
		while (exp_list)
		{
			if (exp_list->value)
				printf("declare -x %s=\"%s\"\n", exp_list->key, exp_list->value);
			// else
			// printf("declare -x %s\n", exp_list->key);
			exp_list = exp_list->next;
		}
	}
}