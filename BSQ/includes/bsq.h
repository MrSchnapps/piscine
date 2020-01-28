/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:02:03 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 16:39:35 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_bsqr
{
	int	max;
	int	x;
	int	y;
}				t_bsqr;

typedef struct	s_bsq
{
	char			valid;
	char			obstacle;
	char			empty;
	char			full;
	unsigned char	*lines;
	unsigned char	**cval;
	short			**sval;
	int				lines_count;
	int				lines_size;
	t_bsqr			r;
}				t_bsq;

void			bsq(char *filename);
t_bsq			bsq_read_firstline(t_bsq bsq, char *line, char *content);
t_bsq			bsq_read(char *content);
t_bsq			bsq_valid_line(t_bsq bsq);
int				bsq_valid_lines(t_bsq bsq);
t_bsqr			bsqr_test(t_bsqr bsqr, int val, int x, int y);
void			bsq_free(t_bsq bsq, char *content);

t_bsq			bsq_resolv_char(t_bsq bsq);
t_bsq			bsq_resolv_algo_char(t_bsq bsq);
t_bsq			bsq_char_to_val(t_bsq bsq);
t_bsq			bsq_val_to_char(t_bsq bsq, int max, int x, int y);

t_bsq			bsq_resolv_short(t_bsq bsq);
t_bsq			bsq_resolv_algo_short(t_bsq bsq);
t_bsq			bsq_short_to_val(t_bsq bsq);
t_bsq			bsq_val_to_short(t_bsq bsq, int max, int x, int y);

int				file_open(char *filename);
int				file_rewind(char *filename, int fd);
int				file_size(int fd);
char			*file_read(char *filename, int fd);
char			*file_read_content(char *filename);

char			*stdin_alloc(char *content, int csize, char *part, int psize);
char			*stdin_read(void);

char			nt_is_space(char c);
int				nt_atoi(char *str);
int				nt_strlen(char *str);
int				nt_min(int a, int b, int c);
int				nt_val(t_bsq *bsq, char c);

char			*str_nextline(char *content);
#endif
