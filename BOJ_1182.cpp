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

int num[20];
int result = 0;
int N, S;

void dfs(int sum, int i) {
	if (i == N) {
		if (sum == S) {
			result += 1;
		}
		return;
	}
	dfs(sum + num[i], i + 1);
	dfs(sum, i+1);
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	dfs(0, 0);
	if (S == 0)
		result -= 1;
	printf("%d\n", result);
	return 0;
}