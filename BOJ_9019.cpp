#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int T, N, K;
bool visited[10000];
char reg[10000];
int state[10000];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		memset(visited, false, sizeof(visited));
		memset(reg, 0, sizeof(reg));
		memset(state, 0, sizeof(state));
		queue<int> q;
		q.push(N);
		visited[N] = true;
		state[N] = -1;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			int tmp = now * 2;
			if (tmp > 9999)
				tmp = tmp % 10000;
			if (visited[tmp] == false) {
				q.push(tmp);
				visited[tmp] = true;
				reg[tmp] = 'D';
				state[tmp] = now;
			}

			tmp = now - 1;
			if (now == 0)
				tmp = 9999;
			if (visited[tmp] == false) {
				q.push(tmp);
				visited[tmp] = true;
				reg[tmp] = 'S';
				state[tmp] = now;
			}

			tmp = (now / 1000) + (now % 1000) * 10;
			if (visited[tmp] == false) {
				q.push(tmp);
				visited[tmp] = true;
				reg[tmp] = 'L';
				state[tmp] = now;
			}

			tmp = (now % 10) * 1000 + (now / 10);
			if (visited[tmp] == false) {
				q.push(tmp);
				visited[tmp] = true;
				reg[tmp] = 'R';
				state[tmp] = now;
			}
		}

		string ans = "";
		while (K != N) {
			ans += reg[K];
			K = state[K];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}

	return 0;
}