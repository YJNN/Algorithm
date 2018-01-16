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

int board[101][101];
long long d[101][101];
//long long ans = 0;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	d[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num = board[i][j];
			if (i + num < n && i!=n-1)
				d[i + num][j] += d[i][j];
			if (j + num < n && j!=n-1)
				d[i][j + num] += d[i][j];
		}
	}
	printf("%lld\n", d[n - 1][n - 1]);

	return 0;
}