#include <stdio.h>

char maze[50][50];

int fx[] = { 1, -1, 0, 0 };
int fy[] = { 0, 0, -1, 1 };

/*void out(char maze[8][8]);*/
int check(char maze[50][50], int n, int m, int i, int j, int pi, int pj);
void search(char maze[50][50], char exit, int n, int m, int i, int j, int prei,
	    int prej);
int main(void)
{
    int temi, temj;
    int i, j;
    int n, m;
    int key;
    if (freopen("maze.in", "r", stdin) == NULL)
	return -1;
    scanf("%d%d", &n, &m);
    scanf("%d", &key);
    for (i = 0; i < n; i++)
	for (j = 0; j < m; j++) {
	    scanf("%c", &maze[i][j]);
	    if (maze[i][j] == '\n')
		scanf("%c", &maze[i][j]);
	}

    for (i = 0; i < n + 1; i++) {
	for (j = 0; j < m; j++) {
	    printf("%c", maze[i][j]);
	}
	printf("\n");
    }
    close(stdin);
    for (i = 0; i < n; i++)
	for (j = 0; j < m; j++) {
	    if (maze[i][j] == '$') {
		temi = i;
		temj = j;
	    }
	}
    printf("%d %d\n", temi, temj);
    search(maze, 'A', n, m, temi, temj, -1, -1);
}

void
search(char maze[50][50], char exit, int n, int m, int i, int j, int prei,
       int prej)
{
    int k, ni, nj;
    if (maze[i][j] == exit) {
	printf("%d %d\n", i, j);
	return;
    }
    for (k = 0; k < 4; k++) {
	ni = i + fx[k];
	nj = j + fy[k];
	if (check(maze, n, m, ni, nj, prei, prej))
	    search(maze, '&', n, m, ni, nj, i, j);
    }
}

int check(char maze[50][50], int n, int m, int i, int j, int pi, int pj)
{
    int flag = 1;
    if (i == pi && j == pj)
	flag = 0;
    if (i < 0 || i > n || j < 0 || j > m)
	flag = 0;
    else if (maze[i][j] != '.' && maze[i][j] != 'a')
	flag = 0;
    return flag;
}
