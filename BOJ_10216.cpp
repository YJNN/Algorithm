#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

#define pos pair<int, int>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

pos enemy[3000];
bool visited[3000];
int rad[3000];
int N;
int cnt = 0;

int dist(pos x, pos y) {
	int a = (x.first - y.first);
	int b = (x.second - y.second);
	return a*a + b*b;
}

void dfs(int idx) {
	for (int i = 0; i < N; i++) {
		int radSum = rad[idx] + rad[i];
		if (idx == i || visited[i] == true || dist(enemy[idx], enemy[i]) > radSum*radSum)
			continue;
		visited[i] = true;
		dfs(i);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			cin >> enemy[i].first >> enemy[i].second >> rad[i];
		}

		for (int i = 0; i < N; i++) {
			if (visited[i] == false) {
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}

	return 0;
}