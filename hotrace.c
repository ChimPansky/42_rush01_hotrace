/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:26:50 by mhuszar           #+#    #+#             */
/*   Updated: 2023/10/16 20:07:44 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

 #include <fcntl.h>
 #undef STDIN_FILENO
 int STDIN_FILENO = 0;

int	read_data(t_keyvalue **hashtable)
{
	char	*line;
	char	*key;
	char	*value;

	line = get_next_line(STDIN_FILENO);
	while (line && *line != '\n')
	{
		key = line;
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return (0);
		value = line;
		if (line && *line != '\n' )
		{
			if (!store_data(hashtable, key, value))
				return (0);
			line = get_next_line(STDIN_FILENO);
			if (!line)
				return (0);
		}
	}
	free(line);
	return (1);
}

int	store_data(t_keyvalue **hashtable, char *key, char *val)
{
	t_keyvalue	*newkeyval;
	size_t		index;

	newkeyval = (t_keyvalue *)malloc(sizeof(t_keyvalue));
	if (newkeyval == NULL)
		return (0);
	newkeyval->key = key;
	newkeyval->val = val;
	newkeyval->hash2 = get_hash2(key);
	index = get_hash(key);
	newkeyval->next = hashtable[index];
	hashtable[index] = newkeyval;
	return (1);
}

void	search_key(t_keyvalue **hashtable, char *search_key)
{
	size_t		index;
	t_keyvalue	*current;

	index = get_hash(search_key);
	current = hashtable[index];
	while (current != NULL)
	{
		if (current->hash2 == get_hash2(search_key))
		{
			ft_putstr_fd(current->val, 1);
			return ;
		}
		current = current->next;
	}
	ft_putstr_fd_nonl(search_key, 1);
	ft_putendl_fd(": Not found.", 1);
}

int	read_search_key(t_keyvalue **hashtable)
{
	char	*line;
	char	*key;

	line = get_next_line(STDIN_FILENO);
	while (line && *line != '\n')
	{
		key = line;
		search_key(hashtable, key);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (line)
		free(line);
	return (1);
}


int	main(void)
{
	t_keyvalue	**hashtab;

	STDIN_FILENO = open("input.txt", O_RDONLY);
	hashtab = (t_keyvalue **)ft_calloc(sizeof(t_keyvalue *), HASHTABLE_SIZE);
	if (!hashtab)
		return (-1);
	if (!read_data(hashtab))
	{
		free_everything(hashtab);
		return (-1);
	}
	if (!read_search_key(hashtab))
	{
		free_everything(hashtab);
		return (-1);
	}
	free_everything(hashtab);
	return (0);
}
