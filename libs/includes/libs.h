/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:47:16 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/02 21:05:04 by jleslee          ###   ########.fr       */
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
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strcpy(char *dest, char *src);

char		*ft_strdup(char *src);
int			ft_strlen(char *str);
int			ft_strncmp(char *str1, char *str2, unsigned int size);
int			ft_strlcpy(char *dst, char *src, unsigned int size);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_3(char **s1, char const *s2);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_whitespace(char cara);
char		**ft_strdoubledup(char **tab);

#endif
