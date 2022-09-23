/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:26:25 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/22 23:20:15 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string_utils.h"
#include <stdio.h>

/*
	Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
*/

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > (size_t)ft_strlen(s))
		return (alloc().calloc(1, sizeof(char)));
	if (len > (size_t)ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = alloc().calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[start + i];
	str[i] = 0;
	return (str);
}

/*
	The strnstr() function locates the first occurrence of the
null-terminated string little in the string big, where not more than
len characters are searched.
Characters that appear after a ‘\0’ characterare not searched.
*/
char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = -1;
	little_len = ft_strlen(little);
	while (big[++i])
	{
		j = -1;
		while (++j + i < len && big[i + j] && \
		little[j] && big[i + j] == little[j])
			;
		if (j == little_len)
			return ((char *)(big + i));
	}
	return (NULL);
}

/*
	It compares if a char c is alphanumeric
*/

int	ft_isalnum(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') \
	|| (c >= 'A' && c <= 'Z'));
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

// Aspas e Duplas Aspas:
// 1- Iterar até encontrar uma aspa;
// 2- Verificar se o caracter a seguir é espaço
// 3A- Caso não seja aspas, iterar até encontrar um espaço
// 3B- Caso seja aspas, incrementar o contador de aspas, e iterar até encontrar a proxima aspa
// - Repetir os passos 

int	check_quotes(char *str, char ap)
{
	int	i;
	int	ct;

	ct = 0;
	i = 0;
	if (*str && *str == ap)
	{
		while (str[++i] && str[i] != ap)
			;
		if (str[i + 1] == ' ')
			return (i + 1);
		while (str[++i])
		{
			while (str[i] && str[i] != ' ')
			{
				if (str[i] == ap)
					ct++;
				i++;
			}
			if (ct % 2 == 0)
				return (i);	
		}
	}
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	if (!s)
		return (0);
	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		//There is an Edgecase here: when the word has quotes in the middle of the word and not beginig
		// example: fasnakn"fas jkj" ->It will separate both
		if (*s == '\'' || *s == '"')
		{
			if (*s == '\'')
				word_len = check_quotes(s, '\'');
			else
				word_len = check_quotes(s, '"');
		}
		else if (!string().strchr(s, c))
			word_len = string().len(s);
		else
			word_len = string().strchr(s, c) - s;
		lst[i++] = string().substr(s, 0, word_len);
		s += word_len;
	}
	lst[i] = NULL;
	return (lst);
}
