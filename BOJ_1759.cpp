#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

bool checkAlpha(string a) {
	int jaum = 0;
	int moum = 0;
	for (char b : a) {
		if (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u') {
			moum += 1;
		}
		else
			jaum += 1;
	}
	return jaum >= 2 && moum >= 1;
}

void dfs(vector<char> &alpha, int L, string pass, int cnt) {
	if (L == pass.length()) {
		if (checkAlpha(pass)) {
			//printf("%s\n", pass);
			//return;
			cout << pass << '\n';
			return;
		}
		//return;
	}
	if (cnt == alpha.size())
		return;
	dfs(alpha, L, pass + alpha[cnt], cnt + 1);
	dfs(alpha, L, pass, cnt + 1);
}

int main()
{
	int L, C;
	//scanf("%d %d", &L, &C);
	cin >> L >> C;
	vector<char> alp(C);
	for (int i = 0; i < C; i++) {
		//scanf("%c", &alp[i]);
		cin >> alp[i];
	}
	sort(alp.begin(), alp.end());
	string c = "";

	dfs(alp,L,c,0);

	return 0;
}