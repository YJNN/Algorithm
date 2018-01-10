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

int R, C, cnt = 1;
char alpha[21][21];
bool visited[26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;

void dfs(int r, int c, int count) {
	if (r < 0 || c < 0 || r>=R || c>=C)
		return;
	if (ans < count)
		ans = count;
	visited[alpha[r][c]-'A'] = true;
	for (int i = 0; i < 4; i++) {
		//if (r + dx[i] >= 0 && c + dy[i] >= 0 && r + dx[i] < R && c + dy[i] < C) {
			if (visited[alpha[r + dx[i]][c + dy[i]] - 'A'] == false) {
				visited[alpha[r + dx[i]][c + dy[i]] - 'A'] = true;
				dfs(r + dx[i], c + dy[i], count + 1);
				visited[alpha[r + dx[i]][c + dy[i]] - 'A'] = false;
			}
	//	}
	}
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> alpha[i][j];
		}
	}
	//visited[alpha[0][0]-'A'] = true;
	dfs(0, 0, 1);
	printf("%d\n", ans);

	return 0;
}