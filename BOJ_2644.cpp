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

int n, m;
int graph[101][101];
int dist[101] = { 0, };
bool visited[101][101];

int main() {
	scanf("%d", &n);
	int start, end;
	scanf("%d %d", &start, &end);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (graph[now][i] == 0 || dist[i] != 0)
				continue;
			dist[i] = dist[now] + 1;
			q.push(i);
		}
	}
	if (dist[end] == 0)
		printf("-1\n");
	else
		printf("%d\n", dist[end]);

	return 0;
}
