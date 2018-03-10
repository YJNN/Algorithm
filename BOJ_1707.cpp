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

int v, e, t;
vector<int> graph[20001];
int visited[20001] = { 0, };

void dfs(int start, int color) {

	for (int i = 0; i < graph[start].size(); i++) {

		if (visited[graph[start][i]] == 0) {
			visited[graph[start][i]] = color * -1;
			dfs(graph[start][i], visited[graph[start][i]]);
		}

	}
}

bool check() {
	for (int i = 1; i <= v; i++) {
		//지금 노드 확인
		int a = visited[i];
		for (int j = 0; j < graph[i].size(); j++) {
			if (a == visited[graph[i][j]]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &v, &e);
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < e; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for (int i = 1; i <= v; i++) {

			if (visited[i] == 0) {
				visited[i] = 1;
				dfs(i, 1);
			}
		}

		bool flag = check();
		if (flag == false)
			printf("NO\n");
		else
			printf("YES\n");

		for (int i = 1; i <= v; i++) {
			graph[i].clear();
		}
	}
	return 0;
}