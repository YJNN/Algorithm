#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n;

int main() {	
	scanf("%d", &n);
	vector<int> permu(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &permu[i]);
	}
	vector<int> operation;
	int arr[4];
	for (int i = 0; i < 4; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++) {
				operation.push_back(i);
			}
		}
	}
	long long sum = 0;
	long long maxNum = -100000000;
	long long minNum = 1000000000;
	do {
		for (int i = 0; i < n - 1; i++) {
			if (i == 0) {
				if (operation[i] == 0) {
					sum = sum + permu[i] + permu[i + 1];
				}
				else if (operation[i] == 1) {
					sum = sum + permu[i] - permu[i + 1];
				}
				else if (operation[i] == 2) {
					sum = sum + permu[i] * permu[i + 1];
				}
				else if (operation[i] == 3) {
					if (permu[i] < 0) {
						permu[i] = permu[i] * -1;
						sum = sum + permu[i] / permu[i + 1];
						sum = sum * -1;
					}
					else
						sum = sum + permu[i] / permu[i + 1];
				
				}
			}
			else {
				if (operation[i] == 0) {
					sum = sum + permu[i + 1];
				}
				else if (operation[i] == 1) {
					sum = sum - permu[i + 1];
				}
				else if (operation[i] == 2) {
					sum = sum * permu[i + 1];
				}
				else if (operation[i] == 3) {
					if (sum < 0) {
						sum = sum * -1;
						sum = sum / permu[i + 1];
						sum = sum * -1;
					}
					else
						sum = sum / permu[i + 1];
				}
			}

		}
		if (maxNum < sum)
			maxNum = sum;
		if (minNum > sum)
			minNum = sum;
		sum = 0;
	} while (next_permutation(operation.begin(), operation.end()));

	printf("%lld\n", maxNum);
	printf("%lld\n", minNum);


	return 0;
}