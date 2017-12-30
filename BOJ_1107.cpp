#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

bool broken[10];

int isPossible(int a) {
	int len = 0;
	if (a == 0) {
		if (broken[a])
			return 0;
		else
			return 1;
	}
	while (a > 0) {
		if (broken[a % 10])
			return 0;
		len += 1;
		a /= 10;
	}
	return len;
}

int main()
{
	int wantedChannel, brokenCnt, brokenNum;
	int curNum = 100;
	cin >> wantedChannel >> brokenCnt;
	for (int i = 0; i < brokenCnt; i++) {
		cin >> brokenNum;
		broken[brokenNum] = true;
	}

	int ans = 0;
	ans = curNum - wantedChannel;
	if (ans < 0)
		ans = wantedChannel - curNum;

	for (int i = 0; i < 1000000; i++) {
		int possibleNum, tmp;
		possibleNum = isPossible(i);

		if (possibleNum > 0) {
			tmp = i - wantedChannel;
			if (tmp < 0)
				tmp = wantedChannel - i;
			if (ans > tmp + possibleNum)
				ans = tmp + possibleNum;
		}
	}

	cout << ans << '\n';

	return 0;
}