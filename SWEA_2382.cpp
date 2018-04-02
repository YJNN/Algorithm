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

vector<int> board[101][101];
//bool visited[101][101];
int n, m, k, t;  //n은 셀개수, m은 격리시간, k는 미생물 군집의 개수
int dx[5] = {0, -1,1,0,0 };   //상하좌우
int dy[5] = {0, 0,0,-1,1 };

struct Node {
	int x;
	int y;
	int misangNum;
	int dir;
};

int main() {
	scanf("%d", &t);
	for(int test=0; test<t; test++) {
		scanf("%d %d %d", &n, &m, &k);
		vector<Node> a(k);
		for (int i = 0; i < k; i++) {
			scanf("%d %d %d %d", &a[i].x, &a[i].y, &a[i].misangNum, &a[i].dir);
			board[a[i].x][a[i].y].push_back(i);
		}

		while (m--) {
			//현재 board 초기화. (초기화하고 이동)
			for (int i = 0; i < k; i++) {
				if (a[i].misangNum == 0)
					continue;
				board[a[i].x][a[i].y].clear();
			}

			//이동
			for (int i = 0; i < k; i++) {
				if (a[i].misangNum == 0)
					continue;
				a[i].x += dx[a[i].dir];
				a[i].y += dy[a[i].dir];
				board[a[i].x][a[i].y].push_back(i);
			}

			for (int i = 0; i < k; i++) {
				if (a[i].misangNum == 0)
					continue;

				if (a[i].x == 0 || a[i].y == 0 || a[i].x == n - 1 || a[i].y == n - 1) {
					a[i].misangNum = a[i].misangNum / 2;
					if (a[i].dir == 1)
						a[i].dir = 2;
					else if (a[i].dir == 2)
						a[i].dir = 1;
					else if (a[i].dir == 3)
						a[i].dir = 4;
					else if (a[i].dir == 4)
						a[i].dir = 3;
				}

				else if (board[a[i].x][a[i].y].size() > 1) {
					int x = a[i].x;
					int y = a[i].y;
					int sum = 0;
					int maxNum = 0;
					int maxDir = 0;
					int tmp=0;
					for (int i = 0; i < board[x][y].size(); i++) {
						sum += a[board[x][y][i]].misangNum;
						if (maxNum < a[board[x][y][i]].misangNum) {
							maxNum = a[board[x][y][i]].misangNum;
							maxDir = a[board[x][y][i]].dir;
							tmp = board[x][y][i];
						}
						a[board[x][y][i]].misangNum = 0;
					}
					a[tmp].misangNum = sum;
					a[tmp].dir = maxDir;
				}

			}
		}
		int ans = 0;
		for (int i = 0; i < k; i++) {
			ans += a[i].misangNum;
		}
		a.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j].clear();
			}
		}
		printf("#%d %d\n", test + 1, ans);
	}

	return 0;
}