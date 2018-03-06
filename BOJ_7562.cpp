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

int t, n;
int board[301][301];
bool visited[301][301];
int dist[301][301];
int startX, startY;
int endX, endY;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%d %d", &startX, &startY);
		queue< pair<int, int> > q;
		q.push(make_pair(startX, startY));
		scanf("%d %d", &endX, &endY);
		memset(visited, false, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		visited[startX][startY] = true;
		dist[startX][startY] = 0;
		while (!q.empty()) {
			int nowX = q.front().first;
			int nowY = q.front().second;
			if (nowX == endX && nowY == endY)
				break;
			q.pop();

			if (nowX - 1 >= 0 && nowY - 2 >= 0 && nowX - 1 < n && nowY - 2 < n && visited[nowX - 1][nowY - 2] == false) {
				visited[nowX - 1][nowY - 2] = true;
				q.push(make_pair(nowX - 1, nowY - 2));
				dist[nowX - 1][nowY - 2] = dist[nowX][nowY] + 1;
			}
			if (nowX - 2 >= 0 && nowY - 1 >= 0 && nowX - 2 < n && nowY - 1 < n && visited[nowX - 2][nowY - 1] == false) {
				visited[nowX - 2][nowY - 1] = true;
				q.push(make_pair(nowX - 2, nowY - 1));
				dist[nowX - 2][nowY - 1] = dist[nowX][nowY] + 1;
			}
			if (nowX - 2 >= 0 && nowY + 1 >= 0 && nowX - 2 < n && nowY + 1 < n && visited[nowX - 2][nowY + 1] == false) {
				visited[nowX - 2][nowY + 1] = true;
				q.push(make_pair(nowX - 2, nowY + 1));
				dist[nowX - 2][nowY + 1] = dist[nowX][nowY] + 1;
			}
			if (nowX - 1 >= 0 && nowY + 2 >= 0 && nowX - 1 < n && nowY + 2 < n && visited[nowX - 1][nowY + 2] == false) {
				visited[nowX - 1][nowY + 2] = true;
				q.push(make_pair(nowX - 1, nowY + 2));
				dist[nowX - 1][nowY + 2] = dist[nowX][nowY] + 1;
			}

			if (nowX + 1 >= 0 && nowY - 2 >= 0 && nowX + 1 < n && nowY - 2 < n && visited[nowX + 1][nowY - 2] == false) {
				visited[nowX + 1][nowY - 2] = true;
				q.push(make_pair(nowX + 1, nowY - 2));
				dist[nowX + 1][nowY - 2] = dist[nowX][nowY] + 1;
			}
			if (nowX + 2 >= 0 && nowY - 1 >= 0 && nowX + 2 < n && nowY - 1 < n && visited[nowX + 2][nowY - 1] == false) {
				visited[nowX + 2][nowY - 1] = true;
				q.push(make_pair(nowX + 2, nowY - 1));
				dist[nowX + 2][nowY - 1] = dist[nowX][nowY] + 1;
			}
			if (nowX + 2 >= 0 && nowY + 1 >= 0 && nowX + 2 < n && nowY + 1 < n && visited[nowX + 2][nowY + 1] == false) {
				visited[nowX + 2][nowY + 1] = true;
				q.push(make_pair(nowX + 2, nowY + 1));
				dist[nowX + 2][nowY + 1] = dist[nowX][nowY] + 1;
			}
			if (nowX + 1 >= 0 && nowY + 2 >= 0 && nowX + 1 < n && nowY + 2 < n && visited[nowX + 1][nowY + 2] == false) {
				visited[nowX + 1][nowY + 2] = true;
				q.push(make_pair(nowX + 1, nowY + 2));
				dist[nowX + 1][nowY + 2] = dist[nowX][nowY] + 1;
			}
		}

		printf("%d\n", dist[endX][endY]);
	}
	return 0;
}
