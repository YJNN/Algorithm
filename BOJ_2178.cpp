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

int N, M;
int miro[101][101];
bool visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dist[101][101];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &miro[i][j]);
		}
	}
	queue< pair<int, int> > q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	dist[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			if (x >= 0 && y >= 0 && x < N && y < M) {
				if (visited[x + dx[i]][y + dy[i]] == false && miro[x+dx[i]][y+dy[i]]==1) {
					q.push(make_pair(x + dx[i], y + dy[i]));
					dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
					visited[x + dx[i]][y + dy[i]] = true;
				}
			}
		}
	}
	printf("%d\n", dist[N-1][M-1]);


	return 0;
}