/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:49:42 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/16 20:07:25 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

// Things we need for Hashtable:
# ifndef HASHTABLE_SIZE
#  define HASHTABLE_SIZE 1000000
# endif

/// Data-Node to store key-value pairs (used in linked list):
// TODO: try adding hash in structure in order to deal with identical
//hashvalues of different keys...
typedef struct s_keyvalue
{
	char				*key;
	char				*val;
	size_t				hash2;
	struct s_keyvalue	*next;
}				t_keyvalue;

size_t	get_hash(char *keyvalue);
size_t	get_hash2(char *keyvalue);
int		read_data(t_keyvalue **hashtable);
int		store_data(t_keyvalue **hashtable, char *key, char *val);
void	free_everything(t_keyvalue **hashtable);

// TODO: Check different GNL-implementations for speed...
// GET_NEXT_LINE:
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 65
# endif
# define MAX_FDS 256

typedef struct s_buffer
{
	char	*cont;
	ssize_t	len;
	ssize_t	last_read;
}				t_buffer;

char	*get_next_line(int fd);
void	free_and_null(void **ptr);
void	*ft_memmove(void *dest, const void *src, size_t n);

//
//char	*ft_strjoin(char *s1, char *s2);

// Helper functions (from libft):
// add prototypes...
size_t	ft_strlen(const char	*s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strdup_nonl(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr_fd_nonl(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putsizet_fd(size_t n, int fd);

// Linked List functions:
void	ft_lstadd_front(t_keyvalue *lst, t_keyvalue new);

#endif
