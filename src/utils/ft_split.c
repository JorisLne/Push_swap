/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:54:53 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/22 16:15:33 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (next_str == NULL)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		i;
	int		words_number;
	char	**sub_str;

	i = 0;
	words_number = count_words(str, separator);
	if (!words_number)
		exit(1);
	sub_str = malloc(sizeof(char *) * (size_t)(words_number + 1));
	if (sub_str == NULL)
		return (NULL);
	while (i < words_number)
	{
		sub_str[i] = get_next_word(str, separator);
		i++;
	}
	sub_str[i] = NULL;
	return (sub_str);
}

void	free_split(char **split_result)
{
	int	i;

	i = 0;
	if (!split_result)
		return ;
	while (split_result[i])
	{
		free(split_result[i]);
		i++;
	}
	free(split_result);
}
