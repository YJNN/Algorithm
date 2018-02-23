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

int n, m;
char board[11][11];
int dx[4] = { -1,1,0,0 };  //À§, ¾Æ·¡, ¿Þ, ¿À
int dy[4] = { 0,0,-1,1 };
int rx, ry, bx, by;   //»¡°­, ÆÄ¶û»ö °ø x,y ÁÂÇ¥
int maxN = 987654321;

bool redFIrstOrNot(int dir) {
	if (dir == 0) {
		if (rx < bx)
			return true;
		else
			return false;
	}
	else if (dir == 1) {
		if (rx > bx)
			return true;
		else
			return false;
	}
	else if (dir == 2) {
		if (ry < by)
			return true;
		else
			return false;
	}
	else{
		if (ry > by)
			return true;
		else
			return false;
	}
}


int move(int dir) {
	bool redTozero=false, blueTozero=false;
	bool stopRed = false, stopBlue = false;
	int cx, cy, nx, ny;
	bool redPriority = redFIrstOrNot(dir);

	while (!stopRed || !stopBlue) {
		if (!stopRed) {
			cx = rx + dx[dir];
			cy = ry + dy[dir];

			if (cx < 0 || cy < 0 || cx >= n || cy >= m || board[cx][cy] == '#')
				stopRed = true;
			else if (board[cx][cy] == 'O') {
				stopRed = true;
				redTozero = true;
			}
			else {
				rx = cx;
				ry = cy;
			}
		}

		if (!stopBlue) {
			nx = bx + dx[dir];
			ny = by + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == '#')
				stopBlue = true;
			else if (board[nx][ny] == 'O') {
				stopBlue = true;
				blueTozero = true;
			}
			else {
				bx = nx;
				by = ny;
			}
		}
	}

	if (rx == bx && ry == by) {
		if (dir == 0) {
			if (redPriority == true) {
				bx++;
			}
			else rx++;
		}
		else if (dir == 1) {
			if (redPriority == true) {
				bx--;
			}
			else rx--;

		}
		else if (dir == 2) {
			if (redPriority == true) {
				by++;
			}
			else ry++;
		}
		else {
			if (redPriority == true) {
				by--;
			}
			else ry--;
		}
	}

	if (blueTozero)
		return 0;
	else if (redTozero)
		return 1;
	else
		return 2;
}

int dfs(int depth){
	if (depth == 10) {
		return maxN;
	}
	int ans = maxN;
	int tmpRx = rx;
	int tmpRy = ry;
	int tmpBx = bx;
	int tmpBy = by;

	for (int i = 0; i < 4; i++) {
		int tmp = move(i);
		if (tmp == 1) {
			return depth + 1;
		}
		else if (tmp == 2) {
			int temp = dfs(depth + 1);
			if (ans > temp)
				ans = temp;
		}
		rx = tmpRx;
		ry = tmpRy;
		bx = tmpBx;
		by = tmpBy;
	}

	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (board[i][j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}

	int ans = dfs(0);
	if (ans == maxN)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}
