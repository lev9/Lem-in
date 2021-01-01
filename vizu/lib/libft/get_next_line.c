/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:07:18 by laskolin          #+#    #+#             */
/*   Updated: 2020/02/13 12:57:11 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_ln(char **line, char **str, int fd)
{
	int		i;
	char	*tmp;

	if (str[fd][0] == '\0')
	{
		ft_strdel(&str[fd]);
		return (0);
	}
	i = 0;
	while (str[fd][i] != '\0' && str[fd][i] != '\n')
		i++;
	if (str[fd][0] == '\n')
		*line = ft_strnew(1);
	else
		*line = ft_strsub(str[fd], 0, i);
	tmp = ft_strsub(str[fd], i + 1, ft_strlen(str[fd]) - i);
	free(str[fd]);
	str[fd] = tmp;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || (!line) || fd > MAX_FD)
		return (-1);
	if (str[fd] && ft_strchr(str[fd], '\n'))
		return (get_ln(line, str, fd));
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
	}
	if (ret == 0 && (!str[fd]))
		return (0);
	return (get_ln(line, str, fd));
}
