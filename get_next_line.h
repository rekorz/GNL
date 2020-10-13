/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 10:26:39 by egallego          #+#    #+#             */
/*   Updated: 2020/09/04 10:26:39 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

int         get_next_line(int fd, char **line);
int         ft_strlen(const char *s);

/* Falta llamar a las funciones adicionales*/

#endif