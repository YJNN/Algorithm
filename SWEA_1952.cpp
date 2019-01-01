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

int t;
int plan[13];
int cost[4];
int minCost;

void dfs(int cnt, int sum) {
	if (sum > minCost)
		return;

	if (cnt > 11) {
		if (minCost > sum) {
			minCost = sum;
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			dfs(cnt + 1, sum + cost[0] * plan[cnt]);
		}
		if (i == 1) {
			dfs(cnt + 1, sum + cost[1]);
		}
		if (i == 2) {
			dfs(cnt + 3, sum + cost[2]);
		}
	}
}

int main() {
	scanf("%d", &t);
	for (int test = 0; test < t; test++) {
		for (int i = 0; i < 4; i++) {
			scanf("%d", &cost[i]);
		}
		for (int i = 0; i < 12; i++) {
			scanf("%d", &plan[i]);
		}
		minCost = cost[3];   //1년 이용권

		dfs(0, 0);
		printf("#%d %d\n", test+1, minCost);
	}
	return 0;
}