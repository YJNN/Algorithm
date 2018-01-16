#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

bool check[1001];
int permu[1001];

void dfs(int vertex) {
	if (check[vertex] == true)
		return;

	check[vertex] = true;
	dfs(permu[vertex]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(check, false, sizeof(check));
		memset(permu, 0, sizeof(permu));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &permu[i]);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i] == false) {
				dfs(i);
				ans++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}