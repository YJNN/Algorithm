#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int M, N, tmpCnt = 0;
int moneCnt = 0;
int box[1001][1001];
bool isVisited[1001][1001];
int dist[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue< pair<int, int> > q;
int cnt = 0;

int main() {
	scanf("%d %d ", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1) {
				dist[i][j] = 0;
				isVisited[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = X + dx[i];
			int cy = Y + dy[i];

			if (box[cx][cy] == 0 && isVisited[cx][cy] == false) {
				if (cx >= 0 && cy >= 0 && cx < N && cy < M) {
					isVisited[cx][cy] = true;
					dist[cx][cy] = dist[X][Y] + 1;
					q.push(make_pair(cx, cy));
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0 && isVisited[i][j]==false) {
				printf("-1\n");
				return 0;
			}
			if (ans < dist[i][j])
				ans = dist[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}