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

int n, k, s;
int graph[401][401];

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k] == 1 && graph[k][j] == 1)
					graph[i][j] = 1;
			}
		}
	}
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (graph[x][y] == 1)
			printf("-1\n");
		else if (graph[y][x] == 1)
			printf("1\n");
		else
			printf("0\n");

	}

	return 0;
}
