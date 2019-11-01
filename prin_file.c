/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prin_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:22:39 by kchen2            #+#    #+#             */
/*   Updated: 2019/11/01 01:17:16 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	error_file(int *flags, char *cmd, char *av, int fd)
{
	flags[ERR]--;
	if (fd == -1)
	{
		ft_putstr(cmd);
		write(1, ": ", 3);
		ft_putstr(av);
		write(1, ": Permission denied\n", 21);
	}
	else
	{
		ft_putstr(cmd);
		write(1, ": ", 3);
		ft_putstr(av);
		write(1, ": Is a directory\n", 18);
	}
}

void	prin_file(int *flags, char *str, char *av, char *s)
{
	hash_table(flags, str, av, s);
	free(str);
}

void	store_file(int *fd, int *flags, char *av, char *s)
{
	int		ret;
	char	*temp;
	char	*str;
	char	buff[2];

	str = ft_strnew(1);
	ret = 0;
	buff[1] = '\0';
	while ((ret = read(*fd, buff, 1)) > 0)
	{
		if (ret == 0)
		{
			*fd = -1;
			break ;
		}
		temp = str;
		str = ft_strjoin(temp, buff);
		free(temp);
	}
	(*fd > -1 && ret > -1) ? prin_file(flags, str, av, s) : flags[ERR]++;
}

void	error_f(char *av, char *cmd)
{
	write(1, "ft_ssl: ", 9);
	ft_putstr(cmd);
	write(1, ": ", 2);
	if (errno == EACCES)
	{
		ft_putstr(av);
		write(1, ": Permission denied\n", 21);
	}
	else if (errno == ENOENT)
	{
		ft_putstr(av);
		write(1, ": No such file or directory\n", 29);
	}
	errno = 0;
}

int		valid_file(char *s, int *flags, char *av)
{
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		error_f(s, av);
	else
		store_file(&fd, flags, av, s);
	close(fd);
	return (fd);
}
