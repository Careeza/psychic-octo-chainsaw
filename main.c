/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:23:52 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/23 18:48:00 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_verif(const char **argv, char **tetri)
{
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if ((i = ft_gnl(fd)) == -1 || i >= 26)
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	if ((tetri = ft_malloc(fd, tetri, i, argv[1])) == NULL)
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	if (ft_good_tetri(tetri, i, -1, 0) == -1)
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	return (tetri);
}

int			backtracking(char *tab, int *iy, int c, t_struct pos)
{
	int verif;

	while (iy[0] <= c * (c + 1) && (verif = ft_abc(&pos, tab, c, iy[0])) == -1)
		iy[0]++;
	if (verif != -1)
	{
		ft_print(tab, iy[1], pos, c);
		iy[1]++;
		iy[0] = 0;
	}
	else
	{
		iy[1]--;
		iy[0] = ft_clear(tab, iy[1]) + 1;
	}
	return (iy[1]);
}

void		ft_algo(char **tetri, int c, char *tab)
{
	t_struct	pos;
	int			iy[2];

	iy[1] = 0;
	while (tetri[iy[1]])
	{
		iy[0] = 0;
		tab = ft_create_tab(c, tab);
		while (iy[1] >= 0 && tetri[iy[1]])
		{
			pos = ft_get_pos(tetri[iy[1]]);
			iy[1] = backtracking(tab, iy, c, pos);
		}
		if (iy[1] == -1)
		{
			c++;
			iy[1] = 0;
		}
	}
	ft_putstr(tab);
	free(tab);
}

int			main(int argc, const char **argv)
{
	char	**tetri;
	char	*tab;
	int		i;

	i = 0;
	tab = NULL;
	tetri = NULL;
	if (argc != 2)
	{
		write(1, "usage: ./fillit filename\n", 25);
		return (0);
	}
	if (!(tetri = ft_verif(argv, tetri)))
		return (0);
	while (tetri[i])
		i++;
	ft_algo(tetri, ft_sqrt(i * 4), tab);
	i = -1;
	while (tetri[++i])
		free(tetri[i]);
	free(tetri);
	return (0);
}
