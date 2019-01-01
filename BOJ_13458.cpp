#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n, allGam, subGam;
long long num = 0;

int main() {
	scanf("%d", &n);
	vector<int> examPlace(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &examPlace[i]);
	}
	scanf("%d %d", &allGam, &subGam);

	for (int i = 0; i < n; i++) {
		long long tmp = 0;
		examPlace[i] = examPlace[i] - allGam;
		if (examPlace[i] == 0) {
			continue;
		}
		else if (examPlace[i] > 0) {
			if (examPlace[i] % subGam == 0)
				num += (examPlace[i] / subGam);
			else
				num += (examPlace[i] / subGam) + 1;
		}
	}
	printf("%ld\n", num+n);


	return 0;
}