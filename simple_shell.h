#ifndef SIMPLE_SHELL_H
# define SIMPLE_SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>

/**
 * struct s_list - struct
 * @content: content
 * @next: next
 */

typedef	struct s_list
{
	char		*content;
	struct s_list	*next;
}	list;

list	*lexecal_analyzer(char *str);
list	*new_node(char *content);
void	add_back(list **lst, list *node);
char	**create_args(list *lexer);
int	listsize(list *lst);
int	exec(char **args, char **env, char **path, char *prog_name);
char	**resize_args(char **args);
int	ft_len(char *str);
char	*add_char(char *buff, char c);
int	built_ins(char *cmd, char **env, char *prog_name, char **path);
int	check_builtins(char *cmd);
int	ft_strcmp(char *a, char *b);
int	ft_strncmp(char *a, char *b, int n);
char	*ft_dup(char *s);
void	delete_args(char **args);
void    delete_lexer(list *lexer);
void	error_generate(char *prog_name);
void	i_do_the_work(char **cmd, char **path, char **env, char *prog_name);
char	*search_in_path(char *cmd, char **path);
void	go_exec(char **args, char **env, char **path, char *prog_name);
int	deal_with_file(char **av, char **env, char **path);
void	delete_2d(char **a);
void	*ft_calloc(size_t count, size_t size);
char	**split(char const *s1, char c);
#endif
