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
int arr[101][101];
int ans[101][101];
int visited[101];

void dfs(int start) {
	for (int i = 0; i < n; i++) {
		if (arr[start][i] == 1 && visited[i] != 1) {
			visited[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i);
		for (int j = 0; j < n; j++) {
			ans[i][j] = visited[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}
