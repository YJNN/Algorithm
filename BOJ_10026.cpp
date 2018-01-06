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

int N;
char pic[101][101];
char sPic[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool check[101][101];
bool sCheck[101][101];
int firstAns, secAns;

void dfs(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N)
		return;
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		if (check[y + dy[i]][x + dx[i]] == false && pic[y + dy[i]][x + dx[i]] == pic[y][x]) {
			dfs(y + dy[i], x + dx[i]);
		}
	}
}
void sdfs(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N)
		return;
	sCheck[y][x] = true;
	for (int i = 0; i < 4; i++) {
		if (sCheck[y + dy[i]][x + dx[i]] == false && sPic[y + dy[i]][x + dx[i]] == sPic[y][x]) {
			sdfs(y + dy[i], x + dx[i]);
		}
	}
}
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//scanf("%c", &pic[i][j]);
			cin >> pic[i][j];
			if (pic[i][j] == 'R')
				sPic[i][j] = 'G';
			else
				sPic[i][j] = pic[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false) {
				firstAns++;
				dfs(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (sCheck[i][j] == false) {
				secAns++;
				sdfs(i, j);
			}
		}
	}
	printf("%d %d\n", firstAns, secAns);
	return 0;
}