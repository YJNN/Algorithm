#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

long long n;
long long storeRoom[100000];

int main() {
	scanf("%lld", &n);
	storeRoom[0] = 1;
	storeRoom[1] = 1;

	for (int i = 2; i < 100000; i++) {
		storeRoom[i] = (i - 1) * 6 + storeRoom[i - 1];
	}

	long long ans = 0;
	if (n == 1)
		ans = 1;
	for (int i = 1; i < 99999; i++) {
		if (n > storeRoom[i] && n <= storeRoom[i + 1]) {
			ans = i + 1;
			break;
		}
	}

	printf("%lld\n", ans);

	return 0;
}
