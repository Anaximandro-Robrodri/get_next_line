#include "get_next_line.h"
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_strcpy (char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char		*str;
	int			i;

	i = ft_strlen(s1);
	str = malloc (i + 1);
	if (str == 0)
		return (0);
	return (ft_strcpy(str, s1));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	if (s)
	{
		if (start < ft_strlen(s))
		{
			i = 0;
			if (len > ft_strlen(s) - start)
				len = ft_strlen(s) - start;
			ptr = malloc(len + 1);
			if (ptr)
			{
				while ((len-- > 0) && (s + start + i++))
					*(ptr + i - 1) = *(s + start + i - 1);
				*(ptr + i) = 0;
				return (ptr);
			}
		}
		else
			return (ft_strdup(""));
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s1 == 0)
		return ((char *) s2);
	if (s2 == 0)
		return ((char *) s1);
	str = malloc ((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (str == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

	char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (0);
}
