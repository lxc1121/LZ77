#include <stdio.h>

int
find(int *arr, int n, int last)
{
	int i;
	int min = arr[1];
	int rt = 1;
	for (i = 2; i < n + 1; i++)
		if (arr[i] < min && arr[i] > last) {
			min = arr[i];
			rt = i;
		}
	return rt;
}

int
check(int *a, int n)
{
	int i;
	for (i = 1; i < n + 1; i++) {
		if (a[i] > 0) ;
		else
			break;
	}
	if (i == n + 1)
		return 0;
	else
		return 1;

}

int
main(void)
{

	int i, j, k;
	int n;
	if (freopen("water.in", "r", stdin) == NULL)
		return -1;
	scanf("%d", &n);
	int arr[n + 1];
	int st[n + 1];
	int barr[n + 1][n + 1];
	for (i = 1; i < n + 1; i++)
		scanf("%d", &arr[i]);

	for (i = 1; i < n + 1; i++)
		for (j = 1; j < n + 1; j++)
			scanf("%d", &barr[i][j]);

	for (i = 0; i < n + 1; i++)
		st[i] = 0;
	k = find(arr, n, 0);

	while (check(st, n) != 0) {
		if (st[k] == 0)
			st[k] = arr[k];
		for (i = 1; i < n + 1; i++) {
			if (st[i] > 0)
				continue;
			int flag = 1;
			if (i == k || barr[i][k] > arr[i])
				continue;
			else {
				if (flag == 1 && st[i] == 0)
					st[i] = barr[i][k];
			}
		}
		k = find(arr, n, st[k]);
	}
	for (i = 1; i < n + 1; i++)
		printf("%d ", st[i]);
	printf("\n");

	return 0;
}
