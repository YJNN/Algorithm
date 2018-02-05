#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <math.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n, m;
int room[9][9];
int tmp[9][9];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[9][9];
int ans;

int main() {
	scanf("%d %d", &n, &m);
	queue< pair<int, int> > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &room[i][j]);
		}
	}

	for (int ax = 0; ax < n; ax++) {
		for (int ay = 0; ay < m; ay++) {
			for (int bx = 0; bx < n; bx++) {
				for (int by = 0; by < m; by++) {
					for (int cx = 0; cx < n; cx++) {
						for (int cy = 0; cy < m; cy++) {
							if (room[ax][ay] || room[bx][by] || room[cx][cy])
								continue;

							room[ax][ay] = 1;
							room[bx][by] = 1;
							room[cx][cy] = 1;
							memset(visited, false, sizeof(visited));

							for (int i = 0; i < n; i++) {
								for (int j = 0; j < m; j++) {
									tmp[i][j] = room[i][j];
								}
							}

							for (int i = 0; i < n; i++) {
								for (int j = 0; j < m; j++) {
									if (tmp[i][j] == 2) {
									
										q.push(make_pair(i, j));
										//visited[i][j] = true;
									}
								}
							}

							while (!q.empty()) {

								int nowX = q.front().first;
								int nowY = q.front().second;
								q.pop();

								for (int k = 0; k < 4; k++) {
									int cx = nowX + dx[k];
									int cy = nowY + dy[k];

									if (tmp[cx][cy] != 1 && tmp[cx][cy]!=2 && cx >= 0 && cy >= 0 && cx < n && cy < m) {
										//visited[cx][cy] = true;
										tmp[cx][cy] = 2;
										//cnt++;
										q.push(make_pair(cx, cy));
									}
								}
							}

							int cnt = 0;
							for (int i = 0; i < n; i++) {
								for (int j = 0; j < m; j++) {
									if (tmp[i][j] == 0)
										cnt++;
								}
							}
					
							ans = max(ans, cnt);
							
							room[ax][ay] = 0;
							room[bx][by] = 0;
							room[cx][cy] = 0;

						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}