#include "push_swap.h"

char	**ft_error(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

int	ft_count_w(const char *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && (s[i] != c))
			cnt++;
		while ((s[i] != c) && s[i])
			i++;
	}
	return (cnt);
}

int	ft_len_w(const char *s, char c, int i)
{
	int	a;

	a = i;
	while ((s[i] != c) && s[i])
		i++;
	return (i - a);
}

char	**ft_write_w(char const *s, char c, char **res, int count)
{
	int	i;
	int	b;
	int	a;

	i = 0;
	a = 0;
	while (a < count)
	{
		b = 0;
		while (s[i] == c)
			i++;
		if (s[i] && (s[i] != c))
		{
			res[a] = (char *)malloc(sizeof(char) * (ft_len_w(s, c, i) + 1));
			if (res[a] == NULL)
				return (ft_error(res));
			res[a][ft_len_w(s, c, i)] = '\0';
		}
		while ((s[i] != c) && (s[i] != '\0'))
			res[a][b++] = s[i++];
		a++;
	}
	res[a] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		count;

	count = ft_count_w(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (res == NULL)
		return (NULL);
	res[count] = NULL;
	if (count == 0)
		return (res);
	res = ft_write_w(s, c, res, count);
	return (res);
}
