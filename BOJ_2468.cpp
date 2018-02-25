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

int n;
int board[101][101];
bool visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 0;
int maxNum = 0;
int tmpMax = 0;

void dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx < 0 || cy < 0 || cx >= n || cy >= n || visited[cx][cy] == true)
			continue;
		visited[cx][cy] = true;
		//cnt++;
		dfs(cx, cy);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] > tmpMax)
				tmpMax = board[i][j];
		}
	}
	for (int i = 0; i <= tmpMax; i++) {
		memset(visited, false, sizeof(visited));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (board[j][k] <= i) {
					visited[j][k] = true;
				}
			}
		}

		for (int m = 0; m < n; m++) {
			for (int l = 0; l < n; l++) {
				if (visited[m][l] == false) {
					visited[m][l] = true;
					dfs(m, l);
					cnt++;
					//cout << cnt;
				}
			}
		}
		if (cnt > maxNum)
			maxNum = cnt;
		cnt = 0;
	}

	printf("%d\n", maxNum);

	return 0;
}
