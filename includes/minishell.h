/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:00:44 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/04 21:08:17 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libs.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <curses.h>
# include <term.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_intra_red
{
	char				*fichier;
	char				*red;
}	t_intra_red;

typedef struct s_cmd
{
	char			*cmd;
	char			*path;
	t_intra_red		*red;
	char			**arg;
	char			*pip;
	pid_t			pid;
	int				tub[2];
	struct s_cmd	*next;
	struct s_cmd	*prev;

}	t_cmd;

typedef struct str_env
{
	char	*key;
	char	*var;
}	t_env;

typedef struct s_term
{
	int		nb_maillon;
	char	**envp;
	char	*str_cmd;
	t_cmd	*cmd;
	t_env	*my_env;
	int		dernier_ret;
}	t_term;

extern t_term	g_term;

# define ENTRE 1
# define SORTI 0

char		*str(char *arg, int tele);
int			check_duplication_key(char *key, int tele);
int			add_new_env(char **key, char **var);
int			added_arg_ex(char **key, char **var);
int			added_arg(char **arg);

int			error_message(char *str);
int			ft_export(char **argv);

t_env		*copy_env(void);
int			sort(t_env **tmp);

int			print_export(void);

void		my_para(int *para, char *str);
int			ft_len_2(char *str);
char		*ft_strmicrojoin(char **str, char c);
int			nmy_gestion_env_heredoc(char **tmp);
int			init_struct_env(void);

int			change_pwd(char *pwd, char *oldpwd);
int			op(char **argv);
int			ft_cd(char **argv);

int			check_building(t_cmd *cmd);

int			option(char *str);
int			ft_echo(char **argv);
int			ft_pwd(t_cmd *cmd);
int			my_env(t_cmd *cmd);

int			ex_exit(int nbr, int err, char *str);
int			verif_arg(char *str);
long long	ft_atoll(char *str);
void		ft_exit(char **argv);

void		supp_var(char *argv);
int			mess_err(char *str);
int			check(char *str);
int			ft_unset(char **argv);


void		*free_tab(void **a_free);
void		*my_free_double_tab(void **tab_str, int nb_str);
void		*listing(t_cmd *cmd);
void		*my_free_maillon(t_cmd *tmp);
int			free_all(int ret);

int			my_sup_maillon(void);
int			launch_ex_2(void);
int			my_print_maillon_2(t_cmd *cmd, int i);

void		handler_ctr_c(int code);
void		handler_ctr_c_2(int code);
void		handler_ctr_backslash(int code);

int			my_print_list_chene(t_cmd *cmd);
int			my_print_maillon(t_cmd *cmd, int i);


int			mise_en_place_de_lancement(int ac, char **envp);
int			my_check_space(char *str);

int			main(int ac, char **av, char **envp);
int			message_error(void);

int			init_parsing(void);

int			my_check_nb_guillemet(char *str);
int			my_check_bad_red(char *str);

int			my_check_gu(int *gu, char c);
int			my_check_red(int gu, char c);
int			my_sup_char(char **str, int x);

char		**my_init_tab_cmd(char *str);

int			my_create_cmd(char **tab_cmd);

int			my_check_red_pip(char *str);
char		*my_recup_ellement(char **str, int *x);
char		*my_take_red(int choose, int *x, char **str);

t_intra_red	*my_recup_red(char **str);

char		*my_recup_cmd(char **str);
char		*my_recup_path(char **str);
char		*my_recup_path_env(char *cmd);
char		*my_recup_pip(char **cmd);

char		**my_recup_arg(char **tab_cmd, t_cmd *cmd);
void		my_close_pip(t_cmd *cmd);

int			launch(void);


int			control_var_env_and_gui(t_cmd *cmd);

int			netoyage_guillemet(char **str);
int			my_check_var_env(char **str);

void		connect_pipe(void);
void		close_pipe(void);
void		creat_pipe(void);

int			connect_redirect(void);

int			connect_heredoc(void);
int			ft_sort_2(char **str, char **res, int option, int *tub);

int			ft_strcmp(char *str1, char *str2);
int			ft_sort(char **str, char **res, int option, int *tub);
int			ft_join(char **res, char *str);
int			clearing_quotes(char **str);
int			ft_heredoc(char *deb, char *fin, int option, int *tub);

int			exec_cmd(void);
#endif
