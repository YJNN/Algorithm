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

int n;

bool compare(pair< int, int > &c1, pair< int, int > &c2) {
	if (c1.second == c2.second) {
		return c1.first < c2.first;
	}
	return c1.second > c2.second;
}

int main() {
	scanf("%d", &n);
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	double sum = 0;
	int sumMean = 0;
	int medianNum = 0;
	int rangeNum = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	sort(arr.begin(), arr.end());

	sumMean = (int)floor((sum / n) + 0.5);
	medianNum = arr[n/2];
	rangeNum = arr.back() - arr.front();

	vector< pair<int, int> > freq;

	for (int i = 0; i < n; i++) {
		if (freq.empty()) {
			freq.push_back(pair<int, int>(arr[i], 1));
			continue;
		}

		if (freq.back().first == arr[i]) {
			pair< int, int > tmp = freq.back();
			tmp.second++;
			freq.pop_back();
			freq.push_back(tmp);

		}
		else {
			freq.push_back(pair<int, int>(arr[i], 1));
		}
	}

	sort(freq.begin(), freq.end(), compare);

	printf("%d\n", sumMean);
	printf("%d\n", medianNum);

	if (freq[0].second == freq[1].second) {
		printf("%d\n", freq[1].first);
	}
	else {
		printf("%d\n", freq[0].first);
	}

	printf("%d\n", rangeNum);


	return 0;
}
