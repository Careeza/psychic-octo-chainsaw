/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:24:24 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/22 15:35:49 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct  s_struct
{
    int tetrix[4];
    int tetriy[4];
    int posx;
    int posy;
}               t_struct;

char	**ft_verif(const char **argv, char **tetri);
char    *ft_algo(char **tetri, int c, char *tab);

#endif