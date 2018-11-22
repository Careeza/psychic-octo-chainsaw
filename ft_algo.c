/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:24:08 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/22 17:32:03 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

void        ft_print(char *tab, int i, t_struct pos, int c)
{
    int         compt;
    static int  lettre;
    int         nbr;

    compt = 1;
    tab[i] = 'A' + lettre;
    while (compt <= 3)
    {
        nbr = (pos.posx + pos.tetrix[compt]) + (pos.posy + pos.tetriy[compt]) * (c + 1);
        tab[nbr] = 'A' + lettre;
        compt++;
    }
    lettre++;
    printf("%s\n", tab);
}
int         ft_abc(t_struct *pos, char *tab, int c, int i)
{
    int compt;
    int nbr;

    compt = 1;
    if ((tab[i] >= 'A' && tab[i] <= 'Z') || tab[i] == '\n')
        return (-1);
    pos->posx = i % (c + 1);
    pos->posy = i / (c + 1);
    while (compt <= 3)
    {
        if (pos->posx + pos->tetrix[compt] >= c || pos->posx + pos->tetrix[compt] < 0)
            return (-1);
        if (pos->posy + pos->tetriy[compt] >= c || pos->posy + pos->tetriy[compt] < 0)
            return (-1);
        nbr = (pos->posx + pos->tetrix[compt]) + (pos->posy + pos->tetriy[compt]) * (c + 1);
        if (tab[nbr] >= 'A' && tab[nbr] <= 'Z')
            return (-1);
        compt++;
    }
    return (0);
}

t_struct    ft_get_pos(char *tetri)
{
    int     i;
    int     y;
    t_struct pos;

    y = 0;
    i = 0;
    while (tetri[i])
    {
        if (tetri[i] >= 'A' && tetri[i] <= 'Z')
        {
            pos.tetrix[y] = i % 5;
            pos.tetriy[y] = i / 5;
            y++;
        }
        i++;
    }
    y = 3;
    while (y >= 0)
    {
        //printf("x1=%d, y1=%d\n",pos.tetrix[y], pos.tetriy[y]);
        pos.tetrix[y] = pos.tetrix[y] - pos.tetrix[0];
        pos.tetriy[y] = pos.tetriy[y] - pos.tetriy[0];
        y--;
    }
    return (pos);
}

char    *ft_create_tab(int c, char *tab)
{
    int i;

    if (!tab)
        free (tab);   
    if (!(tab = (char*)malloc(sizeof(char) * (c * (c + 1) + 1))))
        return (NULL);
    i = 0;
    while (i < (c * (c + 1)))
    {
        if ((i + 1) % (c + 1) == 0)
            tab[i] = '\n';
        else
            tab[i] = '.';
        i++;
    }
    tab[i] = '\0';
    //printf("%s\n", tab);
    return (tab);
}

char    *ft_algo(char **tetri, int c, char *tab)
{
    t_struct pos;
    int i;
    int y;

    y = 0;
    tab = ft_create_tab(c, tab);
    while (tetri[y])
    {
        i = 0;
        pos = ft_get_pos(tetri[y]);
        while (i <= c * (c + 1))
        {
            if (ft_abc(&pos, tab, c, i) == -1)
                i++;
            else
            {
                ft_print(tab, i, pos, c);
                break;
            }
        }
        y++;
    }
    printf("%d\n", y);
   //    ft_algo(**tetri, c + 1)
    return (tab);
}
