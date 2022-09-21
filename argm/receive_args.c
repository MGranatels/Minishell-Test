/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:52:55 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/21 14:14:00 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//CHECK QUOTES IN STRING, ITS MISSPLACED, NEED TO ORGANIZE STILL
int	check_quotes(char *str, int *i)
{
	char	*tmp;
	int		ct;

	ct = *i;
	if (str[*i] == '\'')
	{
		*i += 1;
		while (str[*i] && str[*i] != '\'')
			(*i)++;
		if (*i == string().len(str))
			return (0);
		printf("i = %d\n", *i);
		printf("ct = %d\n", ct);
		tmp = string().substr(str, ct, *i - ct + 1);
		printf("tmp = %s\n", tmp);
		free(tmp);
		return (1);
	}
	if (str[*i] == '"')
	{
		*i += 1;
		while (str[*i] && str[*i] != '"')
			(*i)++;
		tmp = string().substr(str, ct, *i - ct + 1);
		printf("tmp2 = %s\n", tmp);
		free(tmp);
		return (1);
	}
	return (1);
}

int	check_bultin(char *btin, char *str)
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
}

t_command *identify_command(char *str, t_command *vars)
{
	if (check_bultin("echo", str))
	{
		vars = echo_handler(str, vars);
	}
	/* if (check_bultin("cd", str))
		cd_handler(str, vars);
	if (check_bultin("pwd", str))
		pwd_handler(str, vars);
	if (check_bultin("export", str))
		export_handler(str, vars);
	if (check_bultin("unset", str))
		unset_handler(str, vars);
	if (check_bultin("env", str))
		env_handler(str, vars);
	if (check_bultin("exit", str))
		exit_handler(str, vars); */
	return (vars);
}

int	receive_args(char *str)
{
	static	t_command	*vars;

	vars = identify_command(str, vars);
	printlist(vars, 3);
	return (1);
}
