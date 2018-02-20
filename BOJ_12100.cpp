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

int n;
int board[21][21];
int ans = 0;

void move(int dir) {
	queue<int> q;

	if (dir == 0) {  //왼쪽
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] != 0)
					q.push(board[i][j]);
				board[i][j] = 0;
			}
			int y = 0;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				if (board[i][y] == 0)
					board[i][y] = now;
				else if (board[i][y] == now) {
					board[i][y] *= 2;
					y++;
				}
				else
					board[i][++y] = now;
			}
		}
	}

	else if (dir == 1) {   //오른쪽
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (board[i][j] != 0)
					q.push(board[i][j]);
				board[i][j] = 0;
			}
			int y = n - 1;
			while(!q.empty()) {
				int now = q.front();
				q.pop();
	
				if (board[i][y] == 0)
					board[i][y] = now;
				else if (board[i][y] == now) {
					board[i][y] *= 2;
					y--;
				}
				else
					board[i][--y] = now;
			}

		}
	}

	else if (dir == 2) {   //위
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <n; j++) {
				if (board[j][i] != 0)
					q.push(board[j][i]);
				board[j][i] = 0;
			}
			int x = 0;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
	
				if (board[x][i] == 0)
					board[x][i] = now;
				else if (board[x][i] == now) {
					board[x][i] *= 2;
					x++;
				}
				else
					board[++x][i] = now;
			}

		}
	}


	else if (dir == 3) {   //아래
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (board[j][i] != 0)
					q.push(board[j][i]);
				board[j][i] = 0;
			}
			int x = n - 1;
			while (!q.empty()) {
				int now = q.front();
				q.pop();

				if (board[x][i] == 0)
					board[x][i] = now;
				else if (board[x][i] == now) {
					board[x][i] *= 2;
					x--;
				}
				else
					board[--x][i] = now;
			}

		}
	}

}

void dfs(int depth) {
	if (depth == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] > ans)
					ans = board[i][j];
			}
		}
		return;
	}

	int copyMap[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			copyMap[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		move(i);
		dfs(depth + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = copyMap[i][j];
			}
		}
	}

}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", ans);

	return 0;
}