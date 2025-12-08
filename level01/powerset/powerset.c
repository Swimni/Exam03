#include <stdio.h>
#include <stdlib.h>

static int found = 0;

void	backtrack(int *arr, int len, int target, int i, int *set, int size, int sum)
{
	if (sum == target)
	{
		found = 1;
		for (int k = 0; k < size; k++)
		{
			printf("%d", set[k]);
			if (k + 1 < size)
				printf(" ");
		}
		printf("\n");
		return ;
	}
	if (i >= len)
		return ;
	set[size] = arr[i];
	backtrack(arr, len, target, i + 1, set, size + 1, sum + arr[i]);
	backtrack(arr, len, target, i + 1, set, size, sum);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	int	target = atoi(av[1]);
	int	len = ac - 2;

	int	*arr = malloc(sizeof(int) * len);
	int	*set = malloc(sizeof(int) * len);
	if (!arr || !set)
		return (0);
	for (int i = 0; i < len; i++)
		arr[i] = atoi(av[i + 2]);
	backtrack(arr, len, target, 0, set, 0, 0);
	if (!found)
		printf("\n");
	free(arr);
	free(set);
	return (0);
}


