/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:30:31 by sacharai          #+#    #+#             */
/*   Updated: 2024/02/11 16:33:45 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void *ft_malloc(size_t len)
{
    void *rtn;

    rtn = malloc(len);
    if (rtn == NULL)
        exit(1);
    return (rtn);
}

char **list_to_tab(t_env *env_list)
{
    int     count;
    t_env   *current;
    char    **tab;
    int     i;

    count = 0;
    i = 0;
    current = env_list;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    tab = (char **)ft_malloc((count + 1) * sizeof(char *));
    current = env_list;
    while (current != NULL)
    {
        tab[i] = (char *)ft_malloc((ft_strlen(current->key) + 
            ft_strlen(current->value) + 2) * sizeof(char));
        ft_strcpy(tab[i], current->key);
        tab[i][ft_strlen(current->key)] = '=';
        ft_strcpy(tab[i++] + ft_strlen(current->key) + 1, current->value);
        current = current->next;
    }
    return (tab[i] = NULL, tab);
}


int main(int ac, char **av, char **envp) {
    t_env *env = get_env(envp);
    char **tab = list_to_tab(env);
    int i = 0;
    while (tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
    return (0);
}