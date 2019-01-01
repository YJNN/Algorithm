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
bool isPrime[10000];
int dist[10000];

int change(int curNum, int i, int j) {
	if (i == 0 && j == 0)
		return -1;
	string s = to_string(curNum);
	s[i] = j + '0';
	return stoi(s);
}

int main()
{
	for (int i = 2; i < 10000; i++) {
		if (isPrime[i] == false) {
			for (int j = i*i; j < 10000; j += i) {
				isPrime[j] = true;
			}
		}
	}

	for (int i = 2; i < 10000; i++) {
		isPrime[i] = !isPrime[i];
	}


	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		memset(visited, false, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		
		queue<int> q;
		q.push(N);
		dist[N] = 0;
		visited[N] = true;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int cur = change(now, i, j);
					if (cur != -1) {
						if (visited[cur] == false && isPrime[cur]) {
							q.push(cur);
							visited[cur] = true;
							dist[cur] = dist[now] + 1;
						}
					}

				}
			}
		}
		printf("%d\n", dist[K]);
	}

	return 0;
}