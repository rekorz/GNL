/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 10:26:57 by egallego          #+#    #+#             */
/*   Updated: 2020/09/04 10:26:57 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int					has_newline(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if(buf[i] == '\n')
			return (i); 
		i++;	
	}
	return (-1);
}

char				*ft_strdup(const char *s)
{
	int					i;
	int					size;
	char				*str;

	i = 0;
	size = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(*str) * size + 1)))
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[size] = '\0';
	return (str);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		if (!(str = (char*)malloc((ft_strlen(s1) +
							ft_strlen(s2) + 1) * sizeof(char))))
			return (NULL);
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

void			concat_line (char **line, char *frag)
{
	char				*tmp;

	tmp = ft_strjoin(*line, frag);
	free(*line);
	*line = tmp;
}

void			concat_line_by_pos (char **line, char *buf, int pos)
{
	int count;

	count = 0;
	buf[pos++]= 0;
	concat_line(line,buf);
	while (buf[pos])
		buf[count++] = buf[pos++];
	buf[count] = 0;
}


int             get_next_line(int fd, char **line)
{
   	static char             buf[BUFFER_SIZE+1];
    int                 	br;
	int						pos;
	
    if (fd < 0 || BUFFER_SIZE <= 0 || !line)
	{
        return(-1);
	}
	*line = ft_strdup("");
	if ((pos = has_newline(buf)) >= 0)
	{
		concat_line_by_pos(line, buf, pos);
		return (1);
	}
	else
	{
		concat_line (line, buf);
	}
	while (1)
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br < 0)
		{
			free(*line);
			*line = NULL;
			return(-1);
		}
		buf[br] = '\0';
		if (br == 0)
			return (0);
		if ((pos = has_newline(buf)) >= 0)
		{
			concat_line_by_pos(line, buf, pos);
			return (1);
		}
		concat_line (line, buf); 
	}
}