/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:09:39 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/22 23:23:30 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ARGUMENTS_H
# define ARGUMENTS_H

# include "execution.h"

int		receive_args(char *str);

//Manipulate Nodes
t_command	*create_new_node(char *path, t_tmp *args, int st);
t_tmp	*create_single_node(char *value);
int			list_size(t_tmp *list);


//Token Handlers
t_command	*handler(char *str, t_command *vars);

void	printlist(t_command *vars);

#endif