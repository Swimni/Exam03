#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int safe(int *b, int c, int r)
{
	for (int i = 0; i < c; i++)
		if (b[i] == r || (b[i] - r == i - c) || (b[i] - r == c - i))
			return (0);
	return (1);
}

void solve(int *b, int n, int c)
{
	if (c == n)
	{
		for (int i = 0; i < n; i++)
		{
			fprintf(stdout, "%d", b[i]);
			if (i + 1 < n)
				fprintf(stdout, " ");
		}
		fprintf(stdout, "\n");
		return ;
	}
	for (int r = 0; r < n; r++)
		if (safe(b, c, r))
			b[c] = r, solve(b, n, c + 1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	int n = atoi(av[1]);
	if (n <= 3)
		return (write(1, "\n", 1), 0);
	int *b = malloc(sizeof(int) * n);
	if (!b)
		return (1);
	solve(b, n, 0);
	free(b);
	return (0);
}

