#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	elen;
	size_t	ori;

	elen = 0;
	while (dst[elen] && elen < dstsize)
		elen++;
	ori = elen;
	while (src[elen - ori] && elen + 1 < dstsize)
	{
		dst[elen] = src[elen - ori];
		elen++;
	}
	if (ori < dstsize)
		dst[elen] = '\0';
	return (ori + ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*cpy;
	int		i;

	i = 0;
	len = ft_strlen(s);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*strjoin_end(char const *s1, char const *s2, char*cpy)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		cpy[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		cpy[j++] = s2[i];
		i++;
	}
	cpy[j] = '\0';
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	one;
	size_t	two;
	char	*cpy;

	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (NULL);
		if (!s1)
			return (ft_strdup(s2));
		if (!s2)
			return (ft_strdup(s1));
	}
	one = ft_strlen(s1);
	two = ft_strlen(s2);
	cpy = (char *)malloc(sizeof(char) * (one + two + 1));
	if (!cpy)
		return (NULL);
	return (strjoin_end(s1, s2, cpy));
}
