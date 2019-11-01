/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:39:03 by kchen2            #+#    #+#             */
/*   Updated: 2019/03/16 13:48:32 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_new_line(char **s, char **line, int fd)
{
	char		*tmp;
	int			n;

	n = 0;
	while (s[fd][n] != '\n' && s[fd][n] != '\0')
		n++;
	if (s[fd][n] == '\n')
	{
		*line = ft_strndup(s[fd], n);
		tmp = ft_strdup(s[fd] + n + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][n] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*s[4096];
	char		*tmp;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0
		|| BUFF_SIZE < 0 || fd > MAX_FD)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	else
		return (get_new_line(s, line, fd));
}
