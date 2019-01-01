#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


int main()
{
	int E, S, M;
	cin >> E >> S >> M;
	int e = 1;
	int s = 1;
	int m = 1;
	int cnt = 1;

	while (1) {
		if (e == E && s == S && m == M) {
			break;
		}
		e += 1;
		s += 1;
		m += 1;
		cnt += 1;
		if (e > 15)
			e = 1;
		if (s > 28)
			s = 1;
		if (m > 19)
			m = 1;
	}

	cout << cnt << '\n';

	return 0;
}