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
int graph[101][101];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}
	int x, y;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	vector<int> ans(n + 1);
	int minNum = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			ans[i] += graph[i][j];
		}
		if (minNum > ans[i])
			minNum = ans[i];
	}
	for (int i = 1; i <= n; i++) {
		if (minNum == ans[i]) {
			printf("%d\n", i);
			break;
		}	
	}


	return 0;
}
