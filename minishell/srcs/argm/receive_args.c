/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:52:55 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/22 23:24:40 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* int	check_bultin(char *btin, char *str)
{
	int	i;
	int	ct;

	ct = 0;
	i = -1;
	while ((str[++i] && btin[i]) || str[i] == '|')
	{
		if (str[i] == btin[i])
			ct++;
		if (string().len(btin) < string().len(str))
		{
			if (str[string().len(btin)] != ' ')
				return (0);
		}
	}
	if (string().len(btin) == ct)
		return (1);
	return (0);
 }*/

t_command *identify_command(char *str, t_command *vars)
{
	vars = handler(str, vars);
	
	return (vars);
}

int	receive_args(char *str)
{
	static	t_command	*vars;

	vars = identify_command(str, vars);
	//printlist(vars);
	return (1);
}
