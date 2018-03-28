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

int n, m, t;
int friends[10][10];
bool isPair[10];    //짝을 찾았으면 true

int countPairs(bool isPairs[10]) {
	int firstStudent = -1;
	for (int i = 0; i < n; i++) {
		if (isPairs[i] == false) {
			firstStudent = i;
			break;
		}
	}
	if (firstStudent == -1)
		return 1;
	int ret = 0;

	for (int i = firstStudent + 1; i < n; i++) {
		if (isPairs[i] == false && friends[firstStudent][i] == 1) {
			isPairs[firstStudent] = true;
			isPairs[i] = true;
			ret += countPairs(isPairs);
			isPairs[firstStudent] = false;
			isPairs[i] = false;
		}
	}
	return ret;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		memset(isPair, false, sizeof(isPair));
		memset(friends, 0, sizeof(friends));
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			friends[a][b] = 1;
			friends[b][a] = 1;
		}
		printf("%d\n", countPairs(isPair));
	}
	return 0;
}