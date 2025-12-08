#include <stdio.h>
#include <stdlin.h>

static found = 0;

void	backtrack(int *arr, int len, int target, int i, int *set, int size, int sum)
{
	if (sum == target)
	{
		found = 1;
		for (int k = 0; k < size; k++)
