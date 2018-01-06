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

int garo, sero, K;
bool check[51][51];
int cabbage[51][51];
int X, Y;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	if (y < 0 || x < 0 || y >= sero || x >= garo)
		return;
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (check[x + dx[i]][y + dy[i]] == false && cabbage[x + dx[i]][y + dy[i]] == 1) {
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int ans = 0;
		scanf("%d %d %d", &garo, &sero, &K);

		memset(cabbage, 0, sizeof(cabbage));
		memset(check, false, sizeof(check));
		while (K--) {
			scanf("%d %d", &X, &Y);
			cabbage[X][Y] = 1;
		}

		for (int i = 0; i < garo; i++) {
			for (int j = 0; j < sero; j++) {
				if (cabbage[i][j] == 1 && check[i][j] == false) {
					dfs(i, j);
					ans++;
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}