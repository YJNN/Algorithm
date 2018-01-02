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

bool visited[200000];
int dist[200000];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now - 1 >= 0) {
			if (visited[now - 1] == false) {
				q.push(now - 1);
				visited[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}
		}

		if (now + 1 <= 200000) {
			if (visited[now + 1] == false) {
				q.push(now + 1);
				visited[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}

		if (now * 2 <= 200000) {
			if (visited[now * 2] == false) {
				q.push(now * 2);
				visited[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
			}
		}
	}

	printf("%d\n", dist[K]);

	return 0;
}