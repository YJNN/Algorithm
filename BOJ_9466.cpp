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

int n, t;
int arr[100001];
int visited[100001];
int cycle[100001];

int dfs(int start, int curState, int length) {
	visited[curState] = length;
	cycle[curState] = start;
	int next = arr[curState];

	if (visited[next] == 0) {
		dfs(start, next, length + 1);
	}
	else if (visited[next] != 0 && start != cycle[next]) {
		return 0;
	}
	else if (visited[next] != 0 && start == cycle[next]) {
		return length - visited[next] + 1;
	}
}


int main() {
	scanf("%d", &t);
	while (t--) {
		int ret = 0;
		memset(visited, 0, sizeof(visited));
		memset(cycle, 0, sizeof(cycle));
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i] != 0)
				continue;
			if (visited[i] == 0) {
				ret += dfs(i, i, 1);
			}
		}

		printf("%d\n", n - ret);

	}

	return 0;
}