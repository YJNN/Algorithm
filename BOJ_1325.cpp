#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n, m;
vector<int> arr[10001];
int cnt[10001];
int save[10001];
bool visited[10001];

int dfs(int start) {
	if (visited[start] == true)
		return 0;
	visited[start] = true;
	for (int i = 0; i < arr[start].size(); i++) {
		int tmp = arr[start][i];
		save[start] += dfs(tmp);
	}
	return save[start] + 1;
}

int main() {	
	scanf("%d %d", &n, &m);
	int x, y;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		arr[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		memset(save, 0, sizeof(save));
		cnt[i] = dfs(i)-1;
	}
	vector<int> ans;
	int maxNum = cnt[1];
	ans.push_back(1);
	for (int i = 2; i <= n; i++) {
		if (cnt[i] > maxNum) {
			ans.clear();
			maxNum = cnt[i];
		
			ans.push_back(i);
		}
		else if (cnt[i] == maxNum) {
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}