/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:52:12 by mhuszar           #+#    #+#             */
/*   Updated: 2023/10/15 17:52:14 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"
#include <stdio.h>
#include <fcntl.h>
/*
int debug_mode = 0;
int log_coll = 0;
int	print_mode = 0;
int search_input = 0;
int fd;
int fd_output;

void create_search_input(size_t n)
{
	int fd_search = open("search_input.txt", O_RDWR);
	size_t i;
	i = 0;
	while (i < n)
	{
		ft_putsizet_fd(i, fd_search);
		ft_putstr_fd("\n", fd_search);
		i++;
	}
}
void	log_collisions(t_keyvalue **hashtable)
{
	t_keyvalue *current;
	size_t	i;
	int	lst_size;
	size_t coll_count;
	size_t	key_count;
	int fd_coll = open("collisions.txt", O_RDWR);

	coll_count = 0;
	key_count = 0;
	i = 0;
	while (i < HASHTABLE_SIZE)
	{
		lst_size = 0;
		current = hashtable[i];
		while(current != NULL)
		{
			lst_size++;
			key_count++;
			current = current->next;
		}
		if (lst_size > 1)
		{
			coll_count++;
			ft_putstr_fd("---Hashtable Index: ", fd_coll);
			ft_putsizet_fd(i, fd_coll);
			ft_putstr_fd("---\n", fd_coll);
			ft_putstr_fd("Collision Size: ", fd_coll);
			ft_putsizet_fd(lst_size, fd_coll);
			ft_putstr_fd("\n", fd_coll);
			current = hashtable[i];
			while(current != NULL)
			{
				ft_putstr_fd("Key: ", fd_coll);
				ft_putstr_fd_nonl(current->key, fd_coll);
				ft_putstr_fd("\nVal: ", fd_coll);
				ft_putstr_fd_nonl(current->val, fd_coll);
				ft_putstr_fd("\n", fd_coll);
				current = current->next;
			}
			ft_putstr_fd("---End of Index---\n\n", fd_coll);
		}
		i++;
	}
	ft_putstr_fd("Total Number of keys: ", fd_coll);
	ft_putsizet_fd(key_count, fd_coll);
	ft_putstr_fd("\nCollisions found: ", fd_coll);
	ft_putsizet_fd(coll_count, fd_coll);
}

void	print_data(t_keyvalue **hashtable)
{
	size_t i;
	t_keyvalue *current;

	if (debug_mode)
		ft_putendl_fd("PRINT_DATA START", 1);
	i = 0;
	while (i < HASHTABLE_SIZE)
	{
		current = hashtable[i];
		if (current != NULL)
			printf("---START LIST---\n");
		while (current != NULL)
		{
			printf("hashtable[%lu].key: %s", i, current->key);
			printf("hashtable[%lu].value: %s", i, current->val);
			current = current->next;
		}
		i++;
	}
}

size_t get_hash(char *keyvalue)
{
	(void)keyvalue;
    return (1);
}
*/
