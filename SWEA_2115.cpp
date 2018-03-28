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

int board[11][11];
int maxCost[11][11];
int n, m, c, t; //m은 선택할 수 있는 벌통개수, c는 꿀 채취 최대량

int dfs(int beeNum, int x, int y, int sum, int psum) {
	if (beeNum >= m)
		return psum;

	int maxSum = 0;
	int nextSum;
	for (int i = beeNum; i < m; i++) {
		if (sum + board[x][y + i] <= c) {
			nextSum = dfs(i + 1, x, y, sum + board[x][y + i], psum+board[x][y+i]*board[x][y+i]);
			maxSum = max(maxSum, nextSum);
		}
		nextSum = dfs(i + 1, x, y, sum, psum);
		maxSum = max(maxSum, nextSum);
	}

	return maxSum;
}

int selectBee(int x, int y) {
	int sum = 0;
	for (int j = y + m; j < n + m - 1; j++) {
		sum = max(sum, maxCost[x][j]);
	}
	for (int i = x + 1; i < n; i++) {
		for (int j = 0; j < n + m - 1; j++) {
			sum = max(sum, maxCost[i][j]);
		}
	}
	return sum;
}

int main() {
	scanf("%d", &t);
	for (int test = 0; test < t; test++) {
		scanf("%d %d %d", &n, &m, &c);
		memset(maxCost, 0, sizeof(maxCost));
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &board[i][j]);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - m + 1; j++) {
				maxCost[i][j] = dfs(0, i, j, 0, 0);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - m + 1; j++) {
				sum = maxCost[i][j] + selectBee(i, j);
				ans = max(ans, sum);
			}
		}

		printf("#%d %d\n", test+1, ans);

	}

	return 0;
}