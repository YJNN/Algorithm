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

int comNum;
int connectedNum;
int W[101][101];
bool visited[101];
int cnt = 0;

int main() {
	int x, y;
	scanf("%d", &comNum);
	scanf("%d", &connectedNum);
	for (int i = 0; i <connectedNum; i++) {
		//for (int j = 0; j < 2; j++) {
			cin >> x >> y;
			W[x][y] = 1;
			W[y][x] = 1;
		//}
	}
	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int start = q.front();
		q.pop();

		for (int i = 1; i <= comNum; i++) {
			if (W[start][i] == 1 && W[i][start] == 1 && visited[i] == false) {
				q.push(i);
				cnt++;
				visited[i] = true;
			}
		}
	}
	printf("%d\n", cnt);

	return 0;
}