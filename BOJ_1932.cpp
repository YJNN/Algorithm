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
long long arr[501][501];
long long maxNum = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%lld", &arr[i][j]);

			if (j == 1) {
				arr[i][j] = arr[i - 1][j] + arr[i][j];
			}

			else if (j == i) {
				arr[i][j] = arr[i - 1][j - 1] + arr[i][j];
			}

			else {
				arr[i][j] = arr[i][j] + max(arr[i - 1][j - 1], arr[i - 1][j]);
			}

			if (arr[i][j] > maxNum)
				maxNum = arr[i][j];
		}
	}

	printf("%lld\n", maxNum);

	return 0;
}
