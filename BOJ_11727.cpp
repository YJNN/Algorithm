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

int d[1001];

int main() {
	int n;
	scanf("%d", &n);

	d[0] = 0;
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + 2*d[i - 2];
		d[i] = d[i] % 10007;
	}
	//d[n] = d[n] % 10007;

	printf("%d\n", d[n]);


	return 0;
}