/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:23:52 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/22 15:53:54 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int     main(int argc, const char **argv)
{
    char **tetri;
    char    *tab;
    int i;

    i = 0;
    tab = NULL;
	tetri = NULL;
    if (argc != 2)
    {
        write(1, "usage: ./fillit filename\n", 23);
        return (0);
    }
    if (!(tetri = ft_verif(argv, tetri)))
        return (0);
    while (tetri[i])
        i++;
    ft_algo(tetri, ft_sqrt(i * 4), tab);
    return (0);
}