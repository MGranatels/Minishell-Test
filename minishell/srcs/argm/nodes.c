/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:50:29 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/22 23:42:21 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	printlist(t_command *vars)
{
	int	j;

	j = 0;
	printf("\n==============\n");
	while (vars)
	{
		printf("Path == %s\n", vars->path);
		while (vars->args[j])
		{
			printf("Arg[%d] == %s\n", j, vars->args[j]);
			j++;
		}
		printf("Status == [%d] ", vars->status);
		vars = vars->next;
	}

	printf("\n===============\n");
}

int	list_size(t_tmp *list)
{
	int	i;

	i = 0;
	while (list->next)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_tmp	*create_single_node(char *value)
{
	t_tmp	*strc;
	
	strc = (t_tmp *)malloc(sizeof(t_tmp));
	if (!strc)
		return (0);
	strc->args = (char *)malloc(sizeof(char *)* (string().len(value) + 1));
	if (!strc->args)
		return (0);
	strc->args = value;
	strc->next = NULL;
	return (strc);
}


t_command	*create_new_node(char *path, t_tmp *arg_tp, int st)
{
	t_command	*s;
	int			i;
	int			j;
	
	i = list_size(arg_tp) + 1;
	j = i;
	s = (t_command *)malloc(sizeof(t_command));
	if (!s)
		return (0);
	s->args = (char **)malloc(sizeof(char *) * (i + 1));
	if (!s->args)
		return (0);
	if (path)
	{
		s->path = (char *)malloc(sizeof(char ) * string().len(path) + 1);
		if (!s->path)
			return (0);
		s->path = path;
	}
	while (--i >= 0)
	{
		s->args[i] = (char *)malloc(sizeof(char ) * (string().len(arg_tp->args) + 1));
		if (!(s->args[i]))
			return (0);
		s->args[i] = arg_tp->args;
		arg_tp = arg_tp->next;
	}
	s->args[j] = NULL;
	s->status = st;
	s->next = NULL;
	return (s);
}
