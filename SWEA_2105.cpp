#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n, startX, startY, t;
int board[21][21];
bool visited[101];
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { 1,-1,-1,1 };
int ans = 0;

void dfs(int x, int y, int dir, int cnt) {
	if (x >= 0 && y >= 0 && x < n && y < n && visited[board[x][y]] == false) {
		visited[board[x][y]] = true;
		dfs(x + dx[dir], y + dy[dir], dir, cnt + 1);
		dir = (dir + 1) % 4;
		dfs(x + dx[dir], y + dy[dir], dir, cnt + 1);
		visited[board[x][y]] = false;
	}
	
	if (dir == 3 && x == startX && y == startY) {
		if (ans < cnt)
			ans = cnt;
		return;
	}
}

int main()
{
	scanf("%d", &t);
	for (int test = 0; test < t; test++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &board[i][j]);
			}
		}
		ans = 0;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				memset(visited, false, sizeof(visited));
				startX = a;
				startY = b;
				dfs(startX, startY, 0, 0);
			}
		}
		if (ans == 0)
			ans = -1;

		printf("#%d %d\n", test+1, ans);
	}

	return 0;
}