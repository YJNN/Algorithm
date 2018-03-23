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

int n, m, r, c, L, t;
int tunnel[51][51];
int visited[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt;

int chk(int first, int second, int num) {
	if (num == 0) {
		if (first == 1 || first == 2 || first == 4 || first == 7) {
			if (second == 1 || second == 2 || second == 5 || second == 6) {
				return 1;
			}
		}
	}
	else if (num == 1) {
		if (first == 1 || first == 2 || first == 5 || first == 6) {
			if (second == 1 || second == 2 || second == 4 || second == 7) {
				return 1;
			}
		}
	}
	else if (num == 2) {
		if (first == 1 || first == 3 || first == 6 || first == 7) {
			if (second == 1 || second == 3 || second == 4 || second == 5) {
				return 1;
			}
		}
	}

	else if (num == 3) {
		if (first == 1 || first == 3 || first == 4 || first == 5) {
			if (second == 1 || second == 3 || second == 6 || second == 7) {
				return 1;
			}
		}
	}
}

int main() {
	scanf("%d", &t);
	for (int test = 0; test < t; test++) {
		scanf("%d %d %d %d %d", &n, &m, &r, &c, &L);
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &tunnel[i][j]);
			}
		}
		cnt = 1;
		queue< pair<int, int> > q;
		visited[r][c] = 1;
		q.push(make_pair(r, c));

		while (!q.empty()) {
			int first = q.front().first;
			int second = q.front().second;
			q.pop();

			if (visited[first][second] == L)
				continue;

			for (int i = 0; i < 4; i++) {
				int cx = first + dx[i];
				int cy = second + dy[i];

				//if (cx < 0 || cy < 0 || cx >= n || cy >= m)
					//continue;

				if (cx >= 0 && cy >= 0 && cx < n && cy < m) {
					if (visited[cx][cy] == 0 && chk(tunnel[first][second], tunnel[cx][cy], i) == 1) {
						q.push(make_pair(cx, cy));
						visited[cx][cy] = visited[first][second] + 1;
			
						cnt++;
					}
				}
			}
		}
		printf("#%d %d\n", test+1, cnt);
	}
	return 0;
}