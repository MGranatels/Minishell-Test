/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:48:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/22 23:07:23 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_command		t_command;
typedef struct s_redirection	t_redirection;
typedef struct s_tmp			t_tmp;

struct s_tmp
{
	char		*args;
	t_tmp		*next;
};

struct s_command
{
	int			status;
	char		*path;
	char		**args;
	t_command	*next;
};

struct s_redirection
{
	char	*limiter;
	char	*infile;
	int		infd;
	char	*outfile;
	int		outfd;
};

#endif
