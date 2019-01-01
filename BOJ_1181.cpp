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

bool compare(const string &s1, const string &s2) {
	if (s1.size() == s2.size()) {
		return s1 < s2;
	}
	return s1.size() < s2.size();
}

int main() {
	scanf("%d", &n);
	vector<string> str(n);

	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	vector<string>::iterator lastIdx;
	vector<string>::iterator start;

	sort(str.begin(), str.end(), compare);
	lastIdx = unique(str.begin(), str.end());

	for (start = str.begin(); start != lastIdx; start++) {
		cout << *start << '\n';
	}

	return 0;
}
