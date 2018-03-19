#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int m;
int cup[4] = { 0,1,0,0 };

int main() {
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		swap(cup[x], cup[y]);
	}
	bool flag;
	for (int i = 1; i <= 3; i++) {
		if (cup[i] == 1) {
			printf("%d\n", i);
			flag = true;
		}		
	}
	if (flag == false)
		printf("-1\n");

	return 0;
}