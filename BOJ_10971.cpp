#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int W[10][10] = { 0, };

int main()
{
	int cityNum;
	int ans = 987654321;
	scanf("%d", &cityNum);
	for (int i = 0; i < cityNum; i++) {
		for (int j = 0; j < cityNum; j++) {
			scanf("%d", &W[i][j]);
		}
	}
	vector<int> city(cityNum);
	for (int i = 0; i < cityNum; i++) {
		city[i] = i;
	}

	do {
		int sum = 0;
		for (int i = 0; i < cityNum-1; i++) {
			if (W[city[i]][city[i + 1]] == 0) {
				sum += 2000000;
			}
			sum += W[city[i]][city[i + 1]];
		}
		if (W[city[cityNum - 1]][city[0]] == 0)
			sum += 2000000;
		else
			sum += W[city[cityNum - 1]][city[0]];
		if (ans > sum)
			ans = sum;


	} while (next_permutation(city.begin(), city.end()));

	printf("%d\n", ans);

	return 0;
}