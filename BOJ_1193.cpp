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

int main() {
	scanf("%d", &n);
	int cntGroup = 0;
	int sum = 0;

	while (sum < n) {
		cntGroup++;
		sum += cntGroup;
	}

	if ((cntGroup % 2) == 0) {
		int tmpUp = 1;
		int tmpDown = cntGroup;
		for (int i = (sum - cntGroup) + 1; i < n; i++) {
			tmpUp++;
			tmpDown--;
		}
		printf("%d/%d", tmpUp, tmpDown);
	}
	else {
		int tmpUp = cntGroup;
		int tmpDown = 1;
		for (int i = (sum - cntGroup) + 1; i < n; i++) {
			tmpUp--;
			tmpDown++;
		}
		printf("%d/%d", tmpUp, tmpDown);
	}

	return 0;
}
