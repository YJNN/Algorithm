#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n, m;
int board[501][501];
bool visited[501][501];
int maxNum = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
//int minNum = 1000;
int sum = 0;

void dfs(int x, int y, int cnt) {
	if (cnt == 4) {
		if (sum > maxNum)
			maxNum = sum;
		return;
	}
	visited[x][y] = true;
	sum += board[x][y];
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx >= 0 && cy >= 0 && cx < n && cy < m && visited[cx][cy]==false) {
			visited[cx][cy] = true;
			dfs(cx, cy, cnt+1);
			visited[cx][cy] = false;
		}
	}
	visited[x][y] = false;
	sum -= board[x][y];
}

void eDfs(int x, int y) {
	int minNum = 1000;
	sum = board[x][y];
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int curX = x + dx[i];
		int curY = y + dy[i];

		if (curX >= 0 && curY >= 0 && curX < n && curY < m) {
			sum += board[curX][curY];
			cnt++;
			if (minNum > board[curX][curY])
				minNum = board[curX][curY];
		}
	}
	if (cnt == 4) {
		sum -= minNum;
	}

	if (sum > maxNum)
		maxNum = sum;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, 0);
			sum = 0;
			eDfs(i, j);
			sum = 0;
		}
	}

	printf("%d\n", maxNum);

	return 0;
}