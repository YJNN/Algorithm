#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
#include <cstring>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int d[1000001];

int main() {
	int N;
	scanf("%d", &N);

	d[0] = 0;
	d[1] = 0;
	for (int i = 2; i <= N; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 3 == 0) {
			if (d[i] > d[i / 3] + 1) {
				d[i] = d[i / 3] + 1;
			}
		}

		if (i % 2 == 0) {
			if (d[i] > d[i / 2] + 1) {
				d[i] = d[i / 2] + 1;
			}
		}

	}

	printf("%d\n", d[N]);
	return 0;
}