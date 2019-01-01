#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n, m;
int r, c, direct;
int board[51][51];
int dx[4] = { -1,0,1,0};
int dy[4] = { 0,1,0,-1};
int cnt = 1;
bool visited[51][51];

void dfs(int x, int y, int dir) {
	int cx, cy, cd = dir;

	for (int i = 0; i < 4; i++) {
		cd = (cd + 3) % 4;																
		cx = x + dx[cd];
		cy = y + dy[cd];

		if (cx < 1 || cy < 1 || cx >= n - 1 || cy >= m - 1 || board[cx][cy] == 1 || visited[cx][cy]==true)
			continue;

		if (board[cx][cy] == 0) {
			visited[cx][cy] = true;
			cnt++;
			dfs(cx, cy, cd);
			return;
		}
	}

	cd = (dir + 2) % 4;
	cx = x + dx[cd];
	cy = y + dy[cd];
	if (board[cx][cy] == 1)
		return;
	else
		dfs(cx, cy, dir);
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &direct);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	visited[r][c] = true;
	dfs(r, c, direct);

	printf("%d\n", cnt);

	return 0;
}