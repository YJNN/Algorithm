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

int n, k, t;
int graph[9][9];
bool visited[9][9];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int maxx = 1;

void dfs(int x, int y, int maxN, int cut, int length) {
	visited[x][y] = true;
	if (maxx < length)
		maxx = length;

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx < 0 || cy < 0 || cx >= n || cy >= n || visited[cx][cy] == true)
			continue;

		if (graph[cx][cy] < maxN && visited[cx][cy] == false) {
			visited[cx][cy] = true;
			dfs(cx, cy, graph[cx][cy],cut,length+1);
			visited[cx][cy] = false;
		}

		if (graph[cx][cy] >= maxN && visited[cx][cy]==false && cut==0) {
			if (graph[cx][cy] - k < maxN) {
				visited[cx][cy] = true;
				dfs(cx, cy, maxN-1, 1, length+1);
				visited[cx][cy] = false;
			}
		}
	}
	visited[x][y] = false;
}

int main() {
	scanf("%d", &t);
	for(int test=0; test<t; test++) {
		scanf("%d %d", &n, &k);    //k만큼 깎을 수 있음
		memset(visited, false, sizeof(visited));
		//int ans = 0;
		maxx = 1;
		int maxNum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &graph[i][j]);
				maxNum = max(maxNum, graph[i][j]);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] == maxNum) {
					dfs(i, j, graph[i][j], 0, 1);
				}
			}
		}
		printf("#%d %d\n", test+1,maxx);
	}

	return 0;
}