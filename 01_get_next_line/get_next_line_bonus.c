/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:57:11 by psotto-m          #+#    #+#             */
/*   Updated: 2022/11/25 16:57:15 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*print;
	static char	*fdarr [10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	fdarr[fd] = read_to_fdarr(fd, fdarr[fd]);
	if (!fdarr[fd])
		return (NULL);
	print = line_or_eof(fdarr[fd]);
	fdarr[fd] = set_fdarr(fdarr[fd]);
	return (print);
}

char	*read_to_fdarr(int fd, char *fdarr)
{
	char	*buffer;
	int		nbr;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nbr = 1;
	while (!ft_strchr(fdarr, '\n') && nbr != 0)
	{
		nbr = read(fd, buffer, BUFFER_SIZE);
		if (nbr == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbr] = '\0';
		fdarr = ft_strjoin(fdarr, buffer);
	}
	free(buffer);
	return (fdarr);
}

char	*line_or_eof(char *fdarr)
{
	int		i;
	char	*print;

	i = 0;
	if (!fdarr[i])
		return (NULL);
	while (fdarr[i] != '\0' && fdarr[i] != '\n')
		i++;
	print = (char *)malloc(sizeof(char) * (i + 2));
	if (!print)
		return (NULL);
	i = 0;
	while (fdarr[i] != '\0' && fdarr[i] != '\n')
	{
		print[i] = fdarr[i];
		i++;
	}
	if (fdarr[i] == '\n')
	{
		print[i] = '\n';
		i++;
	}
	print[i] = '\0';
	return (print);
}

char	*set_fdarr(char *fdarr)
{
	int		i;
	int		k;
	char	*temp;

	i = 0;
	k = 0;
	while (fdarr[i] != '\0' && fdarr[i] != '\n')
		i++;
	if (!fdarr[i])
	{
		free(fdarr);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(fdarr) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	while (fdarr[i])
		temp[k++] = fdarr[i++];
	temp[k] = '\0';
	free(fdarr);
	return (temp);
}

/* int main ()
{
	char *tester1;
	char *tester2;
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int i = 0;

	while(i <= 9)
	{	
			get_next_line(fd2);
			get_next_line(fd1);
			if(i == 3)
			{
			printf("%s", get_next_line(fd1));
			printf("%s", get_next_line(fd2));
			}
		i++;
	}
} */
