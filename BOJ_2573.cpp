#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define INF 987654321;

int n, m;
int board[301][301];
int tmp[301][301];
bool visited[301][301];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx >= 0 && cy >= 0 && cx < n && cy < m && visited[cx][cy] == false && board[cx][cy] > 0) {
			dfs(cx, cy);
		}
	}
}

int ice(void) {
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false && board[i][j] > 0) {
				tmp++;
				dfs(i, j);
			}
		}
	}
	return tmp;
}

int year(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx >= 0 && cy >= 0 && cx < n && cy < m) {
			if (board[x][y] > 0 && board[cx][cy] <= 0)
				cnt++;
		}
	}
	return cnt;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	int iceNum = 0;
	while ((iceNum=ice()) < 2) {
		if (iceNum == 0) {
			//printf("%d\n", 0);
			ans = 0;
			break;
		}
		memset(visited, false, sizeof(visited));
		ans++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = year(i, j);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] -= tmp[i][j];
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}
