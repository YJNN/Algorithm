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

int n, m, t;
int operCost[22];
int board[21][21];
int ans = 0;

int isPossible(int x, int y, int k) {
	int cnt = 0;
	int endp;
	int nextY;
	for (int i = 1; i <= k - 1; i++) {
		int upNextX = x-k+i;
		int downNextX = x+k-i;
		endp = i * 2 - 1;
		nextY = y - endp / 2;

		for (int j = 0; j < endp; j++) {
			if (upNextX >= 0 && upNextX < n && nextY+j >= 0 && nextY+j < n && board[upNextX][nextY + j] == 1) {
				cnt++;
			}
			if (downNextX >= 0 && downNextX < n && nextY+j >= 0 && nextY+j < n && board[downNextX][nextY + j] == 1) {
				cnt++;
			}
		}
	}
	endp = k * 2 - 1;
	nextY = y - endp / 2;
	for (int j = 0; j < endp; j++) {
		if (x >= 0 && x < n && nextY+j >= 0 && nextY+j < n && board[x][nextY + j] == 1) {
			cnt++;
		}
	}

	if (cnt*m - operCost[k] >= 0)
		return cnt;
	return 0;
}

int main() {
	scanf("%d", &t);
	for (int test = 0; test < t; test++) {
		scanf("%d %d", &n, &m);
		memset(board, 0, sizeof(board));
		for (int i = 1; i < 22; i++) {
			operCost[i] = 2 * i*i - 2 * i + 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &board[i][j]);
			}
		}
		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 1; k <= n + 1; k++) {
					ans = max(ans, isPossible(i, j, k));
				}
			}
		}

		printf("#%d %d\n", test + 1, ans);
	}

	return 0;
}