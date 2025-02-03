/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:42:03 by cbolanos          #+#    #+#             */
/*   Updated: 2025/02/01 12:42:06 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	char	*ptr;
	size_t	len1;
	size_t	len2;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = malloc(len1 + len2 + 1);
	if (!s3)
		return (free(s1), NULL);
	ptr = s3;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	free(s1 - len1);
	return (s3);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*strdup;

	i = 0;
	strdup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!strdup)
		return (NULL);
	while (s[i] != '\0')
	{
		strdup[i] = s[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	char	*subsrtn;

	if (!s)
		return (NULL);
	if (start >= (unsigned int )ft_strlen(s))
	{
		subs = (char *)malloc(sizeof(char));
		if (!subs)
			return (NULL);
		subs[0] = '\0';
		return (subs);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	subsrtn = subs;
	while (s[start] && len--)
		*subs++ = s[start++];
	*subs = '\0';
	return (subsrtn);
}

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
