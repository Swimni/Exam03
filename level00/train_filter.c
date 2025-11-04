#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while (s2[i])
	{
		if (!s1)
			return (0);
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	filter(char *s1, char *s2)
{
	int	i = 0;
	int	len = strlen(s2);
	int	j;
	char	c;

	while (s1[i])
	{
		if (ft_strcmp(&s1[i], s2))
		{
			j = 0;
			while (j < len)
			{
				printf("*");
				i++;
				j++;
			}
		}
		else
		{
			printf("%c", s1[i]);
			i++;
		}
	}
}

int main(int ac, char **av)
{
	char	big[10000];
	int	i = 0;
	int	readed;
	char	c;

	if (ac != 2 || !av[1][0])
		return (1);
	readed = read(0, &c, 1);
	while (readed)
	{
		big[i] = c;
		readed = read(0, &c, 1);
		i++;
	}
	if (readed == -1)
		return (perror("Error"), 0);
	big[i] = '\0';
	filter(big, &av[1][0]);
	return (0);
}


