/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_hashing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:51:21 by mhuszar           #+#    #+#             */
/*   Updated: 2023/10/16 20:27:45 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

size_t	get_hash(char *keyvalue)
{
unsigned	hash;
	unsigned	counter;
	unsigned	hash2;
	unsigned	ch;

	size_t	hashsize;

	if (keyvalue == NULL)
		return (0);
	hashsize = HASHTABLE_SIZE;
	hash = 0;
	counter = 0;
	hash2 = 0;
	while (keyvalue[counter] != '\n')
	{
		ch = keyvalue[counter];

		// __asm__ ("movq $31, %%rdx;"
		// 	"mulq %%rdx;"
		// 	"addq %%rbx, %%rax;"
		// 	"divq %%rcx;"
		// 	: "=d" (hash2)
		// 	: "a" (hash), "b" (ch), "c" (hashsize)
		// 	:
		// 	);
		// hash = hash2;
		hash += (ch * 31) % hashsize;
		counter++;
	}
	return (hash);
}
// size_t	get_hash(char *keyvalue)
// {
// unsigned	hash;
// 	unsigned	counter;
// 	unsigned	hash2;
// 	unsigned ch;

// 	size_t	hashsize;

// 	if (keyvalue == NULL)
// 		return (0);
// 	hashsize = HASHTABLE_SIZE;
// 	hash = 0;
// 	counter = 0;
// 	hash2 = 0;
// 	while (keyvalue[counter] != '\n')
// 	{
// 		ch = keyvalue[counter];

// 		__asm__ ("movq $31, %%rdx;"
// 			"mulq %%rdx;"
// 			"addq %%rbx, %%rax;"
// 			"divq %%rcx;"
// 			: "=d" (hash2)
// 			: "a" (hash), "b" (ch), "c" (hashsize)
// 			:
// 			);
// 		hash = hash2;
// 		counter++;
// 	}
// 	return (hash);
// }

size_t	get_hash2(char *keyvalue)
{
	unsigned	hash;
	unsigned	counter;
	unsigned	hash2;
	unsigned ch;

	if (keyvalue == NULL)
		return (0);
	hash = 0;
	counter = 0;
	hash2 = 0;
	while (keyvalue[counter] != '\n')
	{
		ch = keyvalue[counter];
		__asm__ ("movq $17, %%rdx;"
			"mulq %%rdx;"
			"addq %%rbx, %%rax;"
			"addq %%rcx, %%rax;"
			: "=a" (hash2)
			: "a" (hash), "b" (ch), "c" (counter)
			:
			);
		hash = hash2;
		counter++;
	}
	return (hash);
}

void	free_list(t_keyvalue *list)
{
	t_keyvalue	*current;
	t_keyvalue	*next;

	current = list;
	while (current != NULL)
	{
		next = current->next;
		if (current->key)
			free(current->key);
		if (current->val)
			free(current->val);
		free(current);
		current = next;
	}
}

void	free_everything(t_keyvalue **hashtable)
{
	int	i;

	i = 0;
	while (i < HASHTABLE_SIZE)
	{
		if (hashtable[i] != NULL)
			free_list(hashtable[i]);
		i++;
	}
	free(hashtable);
}
