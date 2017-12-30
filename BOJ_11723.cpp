#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int calCount, S, x;
//string a;
char calc[100];

int main()
{
	//cin >> calCount;
	scanf("%d", &calCount);

	while (calCount--) {
		scanf("%s", &calc);
		if (!strcmp(calc, "add")) {
			//cin >> x;
			scanf("%d", &x);
			x -= 1;
			S = (S | (1 << x));
		}
		else if (!strcmp(calc, "remove")) {
			//cin >> x;
			scanf("%d", &x);
			x -= 1;
			S = (S & ~(1 << x));
		}
		else if (!strcmp(calc, "check")) {
			//cin >> x;
			scanf("%d", &x);
			x -= 1;
			int chk;
			chk = (S & (1 << x));
			if (chk)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (!strcmp(calc, "toggle")) {
			//cin >> x;
			scanf("%d", &x);
			x -= 1;
			S = (S ^ (1 << x));
		}
		else if (!strcmp(calc, "all")) {
			S = (1 << 20) - 1;
		}
		else if (!strcmp(calc, "empty")) {
			S = 0;
		}
	}

	return 0;
}