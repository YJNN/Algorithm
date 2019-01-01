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

int board[21][21];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int L = 1; L <= 2 * n; L++) {
				int w = -(L*L + (L - 1)*(L - 1));
				int cnt = 0;

				for (int x = 1; x <= n; x++) {
					for (int y = 1; y <= n; y++) {
						if (board[x][y] == 0)
							continue;
						int dx = i - x;
						if (dx < 0)
							dx = dx * -1;
						int dy = i - y;
						if (dy < 0)
							dy = dy * -1;
						int dist = dx + dy + 1;
						if (dist <= L) {
							w += m;
							cnt++;
						}
					}
				}

				if (w >= 0 && ans < cnt)
					ans = cnt;

			}
		}
	}
	printf("%d\n", ans);


	return 0;
}