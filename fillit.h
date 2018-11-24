/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:24:24 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/23 13:01:05 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct	s_struct
{
	int tetx[4];
	int tety[4];
	int posx;
	int posy;
}				t_struct;

int				ft_gnl(int fd);
int				ft_check_grille(char *str, int i, int ret);
char			**ft_malloc(int fd, char **tetri, int i, const char *name);
void			ft_extract_tetri(int fd, char **tetri, int i, int j);
int				ft_good_tetri(char **tetri, int i, int j, int k);
char			*ft_create_tab(int c, char *tab);
int				ft_clear(char *tab, int lettre);
t_struct		ft_get_pos(char *tetri);
int				ft_abc(t_struct *pos, char *tab, int c, int i);
void			ft_print(char *tab, int lettre, t_struct pos, int c);
char			**ft_verif(const char **argv, char **tetri);

#endif
