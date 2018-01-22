#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int node[1001][1001] = { 0, };
bool visitedDfs[1001];
bool visitedBfs[1001];

int n, m, v;

void dfs(int start, int end) {
	visitedDfs[start] = true;
	printf("%d ", start);

	for (int i = 1; i <= n; i++) {
		if (node[start][i] == 1 && visitedDfs[i] == false) {
			dfs(i, end);
		}
	}
	return;
}

void bfs(int start, int end) {
	queue<int> q;
	q.push(start);
	visitedBfs[start] = true;
	printf("%d ", start);
	
	while (!q.empty()) {
		int first = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (node[first][i] == 1 && visitedBfs[i] == false) {
				printf("%d ", i);
				visitedBfs[i] = true;
				q.push(i);
	
			}
		}
	}
}

int main() {	
	scanf("%d %d %d", &n, &m, &v);
	int x, y;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		node[x][y] = 1;
		node[y][x] = 1;
	}
	printf("\n");
	bfs(v, n);

	return 0;
}