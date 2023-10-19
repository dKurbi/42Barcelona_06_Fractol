/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:46:53 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/05 11:49:28 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	init(char **rtn, char **read_str, int *i_rtn, int fd)
{
	if (fd < 0)
		return (-1);
	*rtn = NULL;
	*read_str = NULL;
	i_rtn[0] = 1;
	i_rtn[1] = 1;
	i_rtn[2] = 1;
	return (0);
}

static int	manage_storage(char **rtn, char **stor)
{
	int		n_pos;
	char	*swap;
	int		len;

	if (stor && *stor)
	{
		n_pos = check_n(*stor);
		*rtn = join_str_len(NULL, *stor, n_pos);
		len = len_str(*stor);
		if (*rtn == NULL)
			return (-1);
		if (n_pos > -1 && n_pos < len)
		{
			swap = join_str_len(NULL, &(*stor)[n_pos], -1);
			if (swap == NULL)
				return (-1);
			my_free(stor, NULL, NULL);
			*stor = swap;
			return (1);
		}
		my_free(stor, NULL, NULL);
		if (n_pos == len)
			return (1);
	}
	return (0);
}

static int	read_line(int fd, char **read_str, char **rtn)
{
	long	nb;
	long	n_pos;
	char	*swap;

	if (init_read(read_str, &nb, &n_pos) == -1)
		return (-1);
	while ((n_pos == -1 && nb == BUFFER_SIZE))
	{
		nb = read(fd, *read_str, BUFFER_SIZE);
		if (nb == -1)
			return (-1);
		if (nb == 0)
			return (1);
		(*read_str)[nb] = '\0';
		n_pos = check_n(*read_str);
		swap = join_str_len(*rtn, *read_str, n_pos);
		if (swap == NULL)
			return (-1);
		my_free(rtn, NULL, NULL);
		*rtn = swap;
	}
	return (0);
}

static int	save_storage(char **storage, char **read_str)
{
	int	n_pos;

	n_pos = check_n (*read_str);
	if (n_pos != -1 && n_pos < len_str (*read_str))
	{
		*storage = join_str_len(NULL, &(*read_str)[n_pos], -1);
		if (*storage == NULL)
			return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*storage = NULL;
	char			*rtn;
	char			*read_str;
	int				i_rtn[3];

	if (init(&rtn, &read_str, i_rtn, fd) == -1)
		return (NULL);
	i_rtn[0] = manage_storage (&rtn, &storage);
	if (i_rtn[0] == 0)
		i_rtn[1] = read_line (fd, &read_str, &rtn);
	if (i_rtn[0] == 0 && i_rtn[1] == 0)
		i_rtn[2] = save_storage (&storage, &read_str);
	if (i_rtn[0] == -1 || i_rtn[1] == -1 || i_rtn [2] == -1)
	{
		my_free(&read_str, &storage, &rtn);
		return (NULL);
	}
	my_free(&read_str, NULL, NULL);
	return (rtn);
}
