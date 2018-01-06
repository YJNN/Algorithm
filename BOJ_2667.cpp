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
int cnt = 0;
int cityNum = 0;
int pic[25][25];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[25][25];

void dfs(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N)
		return;
	check[y][x] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		if (check[y + dy[i]][x + dx[i]] == false && pic[y + dy[i]][x + dx[i]] == 1) {
			dfs(y + dy[i], x + dx[i]);
		}
	}
}

int main()
{
	int a = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &pic[i][j]);
		}
	}
	vector<int> tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (pic[i][j] == 1 && check[i][j]==false) {
				cityNum++;
				dfs(i, j);
				//tmp[cityNum] = cnt;
				tmp.push_back(cnt);
				cnt = 0;
			}
		}
	}
	printf("%d\n", cityNum);
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		printf("%d\n", tmp[i]);
	}

	return 0;
}