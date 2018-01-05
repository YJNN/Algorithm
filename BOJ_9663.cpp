#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>
//#include <math>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int colNum[15];
int N;
int ans = 0;

void dfs(int x, int y) {
	for (int i = 0; i < y; i++) {
		if (colNum[i] == x || abs(colNum[i] - x) == y - i)
			return;
	}

	if (y == N - 1) {
		ans++;
		return;
	}


	for (int i = 0; i < N; i++) {
		colNum[y + 1] = i;
		dfs(i, y + 1);
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		colNum[0] = i;
		dfs(i,0);
	}
	printf("%d\n", ans);

	return 0;
}