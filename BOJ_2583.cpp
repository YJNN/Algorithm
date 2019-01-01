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

int m, n, k;
int board[101][101];
bool visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 1;

void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx < 0 || cy < 0 || cy >= m || cx >= n || board[cy][cx] == 1 || visited[cy][cx]==true)
			continue;
		visited[cy][cx] = true;
		cnt++;
		dfs(cy, cx);
	}
}

int main() {
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int j = x1; j < x2; j++) {
			for (int l = y1; l < y2; l++) {
				board[l][j] = 1;
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 && visited[i][j] == false) {
				visited[i][j] = true;
				dfs(i, j);
				ans.push_back(cnt);
				cnt = 1;
			}
		}
	}
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}
