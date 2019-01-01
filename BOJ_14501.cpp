#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <math.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n;
bool visited[16];
int consultLength[16];
int money[16];
int ans = 0;

void dfs(int node, int don) {
	if (node >= n+1) {
		if (ans < don)
			ans = don;

		return;
	}

	if(node + consultLength[node] <= n+1)
		dfs(node + consultLength[node], don + money[node]);
	
	if(node + 1 <= n+1)
		dfs(node + 1, don);	
}

int main() {
	scanf("%d", &n);
	int x, y;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		consultLength[i] = x;
		money[i] = y;
	}
	visited[1] = true;
	dfs(1, 0);

	printf("%d\n", ans);


	return 0;
}