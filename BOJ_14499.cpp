#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n, m, x, y;
int dice[6] = { 0, };
int commandCnt;
int board[21][21];
int command[1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void diceRule(int cmd) {
	//µ¿, ¼­, ºÏ, ³²
	if (cmd == 1) {
		swap(dice[1], dice[4]);
		swap(dice[3], dice[4]);
		swap(dice[3], dice[5]);
	}
	else if (cmd == 2) {
		swap(dice[1], dice[5]);
		swap(dice[5], dice[3]);
		swap(dice[3], dice[4]);
	}
	else if (cmd == 3) {
		swap(dice[1], dice[2]);
		swap(dice[0], dice[3]);
		swap(dice[2], dice[0]);
	}
	else if (cmd == 4) {
		swap(dice[3], dice[0]);
		swap(dice[3], dice[1]);
		swap(dice[3], dice[2]);
	}
}


int main() {
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &commandCnt);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	for (int i = 0; i < commandCnt; i++) {
		scanf("%d", &command[i]);
	}

	for (int i = 0; i < commandCnt; i++) {
		int cx = x + dx[command[i] - 1];
		int cy = y + dy[command[i] - 1];

		if (cx < 0 || cy < 0 || cx >= n || cy >= m)
			continue;

		diceRule(command[i]);

		if (board[cx][cy] == 0)
			board[cx][cy] = dice[3];
		else {
			dice[3] = board[cx][cy];
			board[cx][cy] = 0;
		}
		x = cx;
		y = cy;

		printf("%d\n", dice[1]);
	}

	return 0;
}