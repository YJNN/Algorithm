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

int n, color = 0;
int board[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[101][101];
int dist[101][101] = { 0, };


void dfs(int x, int y, int col) {
	visited[x][y] = true;
	board[x][y] = col;

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx >= 0 && cy >= 0 && cx < n && cy < n && visited[cx][cy] == false && board[cx][cy] != 0) {
			dfs(cx, cy, col);
		}
	}
}

int bfs(int color) {
	queue< pair<int, int> > q;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == color) {
				visited[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}
	int tmp = 0;
	while (q.size()) {
		int temp = q.size();
		while (temp--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int cx = x + dx[i];
				int cy = y + dy[i];


				if (cx >= 0 && cy >= 0 && cx < n && cy < n && board[cx][cy] != 0 && board[cx][cy] != color) {
					return tmp;
				}

				if (cx >= 0 && cy >= 0 && cx < n && cy < n && visited[cx][cy] == false && board[cx][cy] == 0) {
					visited[cx][cy] = true;
					q.push(make_pair(cx, cy));
				}
			}
		

		}

		tmp++;
	}

}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j]!=0 && visited[i][j] == false)
				dfs(i, j, ++color);
		}
	}
	int ans = 987654321;
	for (int i = 1; i <= color; i++) {
		memset(visited, false, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		ans = min(ans, bfs(i));
	}

	printf("%d\n", ans);

	return 0;
}