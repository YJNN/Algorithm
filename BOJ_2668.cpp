#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n;
bool visited[101];
int arr[101];
int start;
vector<int> ans;

void dfs(int num, int cnt) {
	visited[num] = true;
	ans.push_back(num);

	if (arr[num] == start && visited[arr[num]] == true)
		return;

	if (visited[arr[num]] == true && arr[num] != start) {
		for (int i = 0; i < cnt; i++) {
			int tmp = ans.back();
			visited[tmp] = false;
			ans.pop_back();
		}
		return;
	}

	if (visited[arr[num]] == false)
		dfs(arr[num], cnt+1);

}


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		start = i;
		dfs(i, 1);
	}

	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}