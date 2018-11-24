/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:24:40 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/23 18:47:40 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_good_tetri(char **tetri, int i, int j, int k)
{
	int vic;

	while (++j <= i)
	{
		vic = 0;
		k = 0;
		while (tetri[j][k])
		{
			if (tetri[j][k] == j + 'A')
			{
				if (k < 20 && tetri[j][k + 1] == (j + 'A'))
					vic++;
				if (k > 0 && tetri[j][k - 1] == (j + 'A'))
					vic++;
				if (k < 16 && tetri[j][k + 5] == (j + 'A'))
					vic++;
				if (k > 4 && tetri[j][k - 5] == (j + 'A'))
					vic++;
			}
			k++;
		}
		if (vic < 6)
			return (-1);
	}
	return (0);
}

void	ft_extract_tetri(int fd, char **tetri, int i, int j)
{
	int		k;
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		k = -1;
		if (line[0] == 0)
		{
			tetri[i][j + 1] = '\0';
			i++;
			j = -1;
		}
		else
		{
			while (k < 4)
			{
				tetri[i][++j] = line[++k];
				tetri[i][j] = tetri[i][j] == '#' ? i + 'A' : '.';
			}
			tetri[i][j] = '\n';
		}
		free(line);
	}
	tetri[i][j + 1] = '\0';
	tetri[i + 1] = NULL;
}

char	**ft_malloc(int fd, char **tetri, int i, const char *name)
{
	int		j;

	close(fd);
	if (!(tetri = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	j = 0;
	while (j <= i)
	{
		if (!(tetri[j] = (char*)malloc(sizeof(char) * (21))))
			return (NULL);
		j++;
	}
	j = -1;
	fd = open(name, O_RDONLY);
	ft_extract_tetri(fd, tetri, 0, -1);
	close(fd);
	return (tetri);
}

int		ft_check_grille(char *str, int i, int ret)
{
	static int	cmt;
	static int	cpt;

	if (str[0] != 0 && ret != 0)
	{
		cpt++;
		if (ft_strlen(str) != 4)
			return (-1);
		while (i < 4)
		{
			if (str[i] == '#')
				cmt++;
			if ((str[i] != '.' && str[i] != '#'))
				return (-1);
			i++;
		}
	}
	else
	{
		if (cmt != 4 || cpt != 4)
			return (-1);
		cmt = 0;
		cpt = 0;
	}
	return (0);
}

int		ft_gnl(int fd)
{
	char	*line;
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 0)
			i++;
		if (ft_check_grille(line, 0, ret) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	ret = get_next_line(fd, &line);
	if (ft_check_grille(line, 0, ret) == -1)
		return (-1);
	return (i);
}
