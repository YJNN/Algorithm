#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> per(N);
	for (int i = 0; i < N; i++) {
		per[i] = i + 1;
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", per[i]);
	}
	printf("\n");

	while (next_permutation(per.begin(), per.end()) == true) {
		for (int i = 0; i < N; i++) {
			printf("%d ", per[i]);
		}
		printf("\n");
	}

	return 0;
}