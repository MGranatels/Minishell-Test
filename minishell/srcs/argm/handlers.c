/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/22 23:52:02 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tmp	*str_handler(char *str, t_tmp *head, t_tmp *arg)
{
	char	**split;
	int		i;
	int		sz;
	
	i = -1;
	sz = 0;
	split = string().ft_split(str, ' ');
	while (split[sz])
		sz++;
	while (split[++i])
	{
		arg = create_single_node(split[i]);
		arg->next = head;
		head = arg;		
	}
	return (head);
}

t_command	*handler_path(char *str, t_tmp *head, t_tmp *args, t_command *vars)
{
	int		i;
	char	*path;
	
	i = 0;
	while (*str && *str == ' ')
		str++;
	if (*str != '/')
		return (NULL);
	while (str[i] && (string().ft_isalnum(str[i]) || str[i] == '/'))
		i++;
	path = string().substr(str, 0, i);
	str = str + i;
	head = str_handler(str, head, args);
	vars = create_new_node(path, head, 0);
	return (vars);
}

t_command	*handler(char *str, t_command *vars)
{
	static	t_tmp	*head;
	static	t_tmp	*args;
	
	vars = 	handler_path(str, head, args, vars);
	printlist(vars);
	// DON'T FORGET TO CLEAN THE tmp_LIST 
	// And the path char
	return (vars);
}