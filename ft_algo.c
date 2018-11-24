/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:24:08 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/23 19:13:03 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print(char *tab, int lettre, t_struct pos, int c)
{
	int			cpt;
	int			nbr;

	cpt = 0;
	while (cpt <= 3)
	{
		nbr = (pos.posx + pos.tetx[cpt]) + (pos.posy + pos.tety[cpt]) * (c + 1);
		tab[nbr] = 'A' + lettre;
		cpt++;
	}
}

int			ft_abc(t_struct *pos, char *tab, int c, int i)
{
	int cpt;
	int nbr;

	cpt = 1;
	if ((tab[i] >= 'A' && tab[i] <= 'Z') || tab[i] == '\n')
		return (-1);
	pos->posx = i % (c + 1);
	pos->posy = i / (c + 1);
	while (cpt <= 3)
	{
		if (pos->posx + pos->tetx[cpt] >= c || pos->posx + pos->tetx[cpt] < 0)
			return (-1);
		if (pos->posy + pos->tety[cpt] >= c || pos->posy + pos->tety[cpt] < 0)
			return (-1);
		nbr = (pos->posx + pos->tetx[cpt]) + (pos->posy + pos->tety[cpt]) *
			(c + 1);
		if (tab[nbr] >= 'A' && tab[nbr] <= 'Z')
			return (-1);
		cpt++;
	}
	return (0);
}

t_struct	ft_get_pos(char *tetri)
{
	int			i;
	int			y;
	t_struct	pos;

	y = 0;
	i = 0;
	while (tetri[i])
	{
		if (tetri[i] >= 'A' && tetri[i] <= 'Z')
		{
			pos.tetx[y] = i % 5;
			pos.tety[y] = i / 5;
			y++;
		}
		i++;
	}
	y = 3;
	while (y >= 0)
	{
		pos.tetx[y] = pos.tetx[y] - pos.tetx[0];
		pos.tety[y] = pos.tety[y] - pos.tety[0];
		y--;
	}
	return (pos);
}

char		*ft_create_tab(int c, char *tab)
{
	int		i;
	char	*temp;

	temp = tab;
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
	free(temp);
	return (tab);
}

int			ft_clear(char *tab, int lettre)
{
	int i;
	int save;

	i = 0;
	save = -1;
	while (tab[i])
	{
		if (tab[i] == lettre + 'A' && save == -1)
			save = i;
		if (tab[i] == lettre + 'A')
			tab[i] = '.';
		i++;
	}
	return (save);
}
