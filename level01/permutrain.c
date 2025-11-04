#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i = 0;
	
	while (s[i])
		i++;
	return (i);
}

void	ft_swap(char *a, char *b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort(char *str)
{
	for(int i = 0; str[i]; i++)
		for(int j = 0; str[j]; j++)
			if (str[j] > str[i])
				ft_swap(&str[i], &str[j]);
}

int	permute(char *str, int len)
{
	int i = len - 2;
	int j = len - 1;
	int r = len - 1;
	int l;

	while (i >= 0 && str[i] >= str[i + 1])
		i--;
	if (i < 0)
		return (0);
	while (str[j] <= str[i])
		j--;
	ft_swap(&str[i], &str[j]);
	l = i + 1;
	while (l < r)
		ft_swap(&str[l++], &str[r--]);
	return (1);
}

int	main(int ac, char **av)
{
	char	*str;
	int	i = 0;

	if (ac != 2)
		return (1);
	str = malloc(ft_strlen(av[1]) + 1);
	if (!str)
		return (1);
	while (av[1][i])
	{
		str[i] = av[1][i];
		i++;
	}
	str[i] = '\0';
	ft_sort(str);
	puts(str);
	while (permute(str, ft_strlen(str)))
		puts(str);
	free(str);
	return (0);
}


