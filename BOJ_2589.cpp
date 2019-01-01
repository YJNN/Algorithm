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
char board[51][51];
int dist[51][51] = { 0, };
bool visited[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int maxNum = 0;
queue< pair<int, int> > q;

void bfs(int x, int y) {
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cx = nowX + dx[i];
			int cy = nowY + dy[i];

			if (cx >= 0 && cy >= 0 && cx < n && cy < m && board[cx][cy] == 'L' && visited[cx][cy]==false) {
				visited[cx][cy] = true;
				dist[cx][cy] = dist[nowX][nowY] + 1;
				if (dist[cx][cy] > maxNum)
					maxNum = dist[cx][cy];
				q.push(make_pair(cx, cy));
				//bfs(cx, cy);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'L') {
				memset(visited, false, sizeof(visited));
				memset(dist, 0, sizeof(dist));
				visited[i][j] = true;
				bfs(i, j);
			}
		}
	}
	printf("%d\n", maxNum);

	return 0;
}