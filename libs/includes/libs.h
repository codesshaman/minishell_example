/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:47:16 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/01 21:10:02 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdarg.h>
# include <inttypes.h>

# define BUFFER_SIZE 2
# define MIN -2147483648
# define MAX 2147483647

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"
# define NOT_SET -1

# define BLEU "\e[1;36m"
# define BLEU_2 "\e[1;34m"
# define ROUGE "\e[1;31m"
# define VERT "\e[1;32m"
# define JAUNE "\e[1;33m"
# define VIOLET "\e[1;35m"
# define BLANC "\e[0m"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_precision	t_prec;
struct	s_precision {
	int					sub;
	int					align_right;
	int					size;
	int					after_dot;
	char				type;
};

int		ft_printf(const char *str, ...);
int		ft_lst_new_prec(t_prec **lst);
char	*ft_convert_hex(long int var, char *base_to);
char	*convert_number(long long nbr, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_process_args(const char *s, va_list arg, t_prec *lst);
void	ft_treat_prec(va_list arg, int *i, const char *str, t_prec **lst);
void	ft_arg_c(va_list arg, char c, t_prec **lst, int *size);
void	ft_arg_d(va_list arg, t_prec **lst, int *size, int is_signed);
void	ft_arg_s(va_list arg, t_prec **lst, int *size);
void	ft_arg_x(va_list arg, char base, t_prec **lst, int *size);
void	ft_arg_p(va_list arg, t_prec **lst, int *size);
void	ft_lst_prec_delone(t_prec **lst);
int		ft_part_putstr(const char *s, size_t i);
int		ft_print_char(char c, int nb);
char	*ft_utoa(unsigned int nb);
char	**ft_strdoublejoin(char **tab, char *str);

int			ft_putchar(int c);
int			get_next_line(int fd, char **line);
int			get_next_line_2(char **lines, char *buf, int end_buff);
int			get_next_line_3(char **lines);
char		*ft_strjoin_2(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen_2(const char *s);
char		*ft_alloc(size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strcpy(char *dest, char *src);
int			ft_putstr(char *str);
char		*ft_strdup(char *src);
int			ft_strlen(char *str);
int			ft_strncmp(char *str1, char *str2, unsigned int size);
int			ft_strlcpy(char *dst, char *src, unsigned int size);
int			ft_strlcat(char *dst, char *src, unsigned int size);
char		*ft_strnstr(char *str, char *sous_str, unsigned int size);
void		*ft_memset(void *a, int c, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_3(char **s1, char const *s2);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_strtrim(char const *s, char const *set);
void		*ft_calloc(size_t nb, size_t len_nb);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_split(char const *s, char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
t_list		*ft_lstnew(void *content);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
int			ft_whitespace(char cara);
void		ft_free_double_tab_char(char **tab);
int			ft_strlen_moin_whitespace(char *str);
void		ft_sans_whitespace(char *str, char **res);
char		*ft_convertisseur_decimale_en_binaire(int a);
int			ft_convertisseur_binaire_en_decimale(char *binaire);
int			ft_puissance(int nb, int puissance);
char		*ft_relloc(char **str, int len_more);
void		ft_affichage_binaire(char c);
char		**ft_strdoubledup(char **tab);

#endif
