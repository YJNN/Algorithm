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

int Graph[1001][1001];
bool visited[1001];
int n, m, x, y;
int cnt = 0;

void dfs(int vertex) {
	visited[vertex] = true;
	for (int i = 1; i <= n; i++) {
		if (Graph[vertex][i] == 1 && visited[i] == false) {
			dfs(i);
		}
	}
	return;
}

int main() {	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n", cnt);


	return 0;
}