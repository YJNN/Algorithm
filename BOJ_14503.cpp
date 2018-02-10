#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int N, M;
int x, y, d;
int map[51][51];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int move(int d, int state);

int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &x, &y, &d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	map[x][y] = 2;
	int curX;
	int curY;
	int count = 0;
	int result = 1;
	while (1) {
		if (count == 4) {
			d = move(d, 1);
			curX = x + dx[d];
			curY = y + dy[d];
			if (curX < 0 || curY < 0 || curX >= N || curY >= M || map[curX][curY] == 1)
				break;
			x = curX;
			y = curY;
			d = move(d, 1);
			count = 0;
			continue;
		}

		d = move(d, 0);
		curX = x + dx[d];
		curY = y + dy[d];
		count++;

		if (curX < 0 || curY < 0 || curX >= N || curY >= M || map[curX][curY] != 0)
			continue;
		x = curX;
		y = curY;
		map[x][y] = 2;
		result++;
		count = 0;
	}
	printf("%d\n", result);

	return 0;
}

int move(int d, int state) {
	if (state == 0) {
		if (d == 0)
			return 3;
		else if (d == 1)
			return 0;
		else if (d == 2)
			return 1;
		else
			return 2;
	}
	else
		return (d + 2) % 4;
}
