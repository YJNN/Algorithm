#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

bool visited[1000001];
int dist[1000001];

int main()
{
	int maxStair, nowPos, destPos, up, down;
	scanf("%d %d %d %d %d", &maxStair, &nowPos, &destPos, &up, &down);

	queue<int> q;
	q.push(nowPos);
	visited[nowPos] = true;
	dist[nowPos] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == destPos)
			break;

		int next = now + up;
		if (visited[next] == false && next <= maxStair && next>=1) {
			visited[next] = true;
			dist[next] = dist[now] + 1;
			q.push(next);
		}

		next = now - down;
		if (visited[next] == false && next >= 1 && next<=maxStair) {
			visited[next] = true;
			dist[next] = dist[now] + 1;
			q.push(next);
		}
	}
	if (dist[destPos] != 0)
		printf("%d\n", dist[destPos]);
	else if (nowPos == destPos)
		printf("0\n");
	else
		printf("use the stairs\n");
	
	return 0;
}