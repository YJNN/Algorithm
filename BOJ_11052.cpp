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


int main() {
	int n;
	scanf("%d", &n);
	vector<int> num(n+1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	vector<int> d(n + 1);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], num[j] + d[i - j]);
		}
	}

	printf("%d\n", d[n]);


	return 0;
}