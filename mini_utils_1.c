/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elen_t13 <elen_t13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:50:05 by etamazya          #+#    #+#             */
/*   Updated: 2024/12/23 19:26:57 by elen_t13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check_print
char	*check_env_var(t_env *env_lst, const char *context)
{
	t_env	*tmp;

	tmp = env_lst;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, context) == 0)
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

short	del_t_node(t_token *lst)
{
	t_token	*tmp;

	if (lst == NULL || lst->next == NULL)
		return (-1);
	tmp = lst->next;
	lst->next = tmp->next;
	// lst->next = lst->next->next;
	free(tmp->context);
	free(tmp);
	return (0);
}

void	clean_env_list(t_env **list)
{
	t_env	*temp;
	t_env	*next;

	temp = *list;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*list = NULL;
}
