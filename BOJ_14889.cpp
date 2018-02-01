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
int level[21][21];
bool visited[21];
int ans = 987654321;
int res1=0, res2 = 0;
int res = 0;

void dfs(int node, int len) {
	if (len == (n / 2)) {

		vector<int> start(n/2+1);
		vector<int> link(n/2+1);
		int tmp1 = 1, tmp2 = 1;
		for (int i = 1; i <= n; i++) {
			if (visited[i] == true) {
				start[tmp1++] = i;
				//start.push_back(i);
			}
			else
				link[tmp2++] = i;
				//link.push_back(i);
		}
		
		for (int i = 1; i <= len; i++) {
			for (int j = i+1; j <= len; j++) {
				res1 += level[start[i]][start[j]];
				res1 += level[start[j]][start[i]];
			}
		}
		for (int i = 1; i <= len; i++) {
			for (int j = i + 1; j <= len; j++) {
				res2 += level[link[i]][link[j]];
				res2 += level[link[j]][link[i]];
			}
		}

		res = abs(res1 - res2);
		if (ans > res)
			ans = res;
		//start.clear();
		//link.clear();
		res1 = 0;
		res2 = 0;
		res = 0;
		//return;
	}
	else {
		for (int i = node + 1; i <= n; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				dfs(i, len + 1);
			}
		}
	}

	visited[node] = false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &level[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", ans);

	return 0;
}