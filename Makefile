# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 15:14:49 by mbonnet           #+#    #+#              #
#    Updated: 2022/06/03 20:09:51 by jleslee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell 

SRCS			=	main.c\
					hendler/hendler.c\
					building/unset.c\
					building/cd.c\
					building/exit.c\
					building/echo_pwd_env.c\
					building/export/export.c\
					building/export/fix_export.c\
					building/export/add_env_export.c\
					building/export/print_export.c\
					building/check_building.c\
					free/free.c\
					init_struct_env.c\
					parser/init_parsing.c\
					parser/check_str_cmd.c\
					parser/utile.c\
					parser/init_tab_cmd/init_tab_cmd.c\
					parser/init_struct/init_struct.c\
					parser/init_struct/utile.c\
					parser/init_struct/gestion_red.c\
					parser/init_struct/gestion_cmd.c\
					parser/init_struct/gestion_arg.c\
					ex_cmd/lancement_ex.c\
					ex_cmd/gestion_gu_and_var_env.c\
					ex_cmd/gestion_gu_and_var_env_utile.c\
					ex_cmd/gestion_tub.c\
					ex_cmd/gestion_red.c\
					ex_cmd/gestion_heredoc.c\
					ex_cmd/gestion_heredoc_2.c\
					ex_cmd/gestion_ex.c\

OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

HEAD			=	-I includes -I libs/includes

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra -g 

LIBS_DIR		=	libs

LDFLAGS			=	-L ${LIBS_DIR} -lft 

.c.o			:
					${CC} ${CFLAGS} ${HEAD}  -c $< -o ${<:.c=.o} 

$(NAME)			:	${OBJS} ${LIBS_DIR}
					make -C ${LIBS_DIR}
					${CC} ${CFLAGS} -lreadline ${OBJS} ${LDFLAGS} -o ${NAME} -lncurses


all				:	${NAME}

clean			:
					make clean -C ${LIBS_DIR}
					rm -rf ${OBJS}

fclean			:	clean
					make fclean -C ${LIBS_DIR}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
