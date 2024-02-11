/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:02:03 by sacharai          #+#    #+#             */
/*   Updated: 2024/02/11 19:32:13 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(t_ex *cmds)
{
	if (!ft_strcmp(cmds->cmd[0], "export"))
		return (1);
	else if (!ft_strcmp(cmds->cmd[0], "echo"))
		return (1);
	else if (!ft_strcmp(cmds->cmd[0], "pwd"))
		return (1);
	else if (!ft_strcmp(cmds->cmd[0], "env"))
		return (1);
	else if (!ft_strcmp(cmds->cmd[0], "exit"))
		return (1);
	else if (!ft_strcmp(cmds->cmd[0], "cd"))
		return (1);
	else if (!ft_strcmp(cmds->cmd[0], "unset"))
		return (1);
	else
		return (0);
}
int	exec_builtin(char **cmds, t_env *env_list)
{
	if (!ft_strcmp(cmds[0], "echo"))
		return(ft_echo(cmds), 0);
	else if (!ft_strcmp(cmds[0], "exit"))
		return(ft_exit(cmds), 0);
	else if (!ft_strcmp(cmds[0], "unset"))
		return(ft_unset(cmds), 0);
	else if (!ft_strcmp(cmds[0], "env"))
		return(ft_env(cmds), 0);
	else if (!ft_strcmp(cmds[0], "export"))
		return(ft_export(cmds), 0);
	else if (!ft_strcmp(cmds[0], "cd"))
		return(ft_cd(cmds), 0);
	else if (!ft_strcmp(cmds[0], "pwd"))
		return(ft_pwd(cmds), 0);
	else
		return (1);
}

void	normal_exec(t_var *cmds, t_env *env_list)
{
    
    while (cmds->cmd)
    
    if (cmds->cmd == 0)
    {
        if (is_builtin(cmds->cmd))
            exec_builtin(cmds->cmd, env_list);

    }
    
}

void	execution(t_var *cmds, t_env *env_list)
{
	normal_exec(cmds, env_list);
}