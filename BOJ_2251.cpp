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

bool visited[201][201];
bool amountC[201];
int A, B, C;

void dfs(int a, int b, int c) {
	if (visited[a][b])
		return;
	if (a == 0)
		amountC[c] = true;
	visited[a][b] = true;

	if (a + b > B)
		dfs((a + b) - B, B, c);
	else
		dfs(0, a + b, c);

	if (a + b > A)
		dfs(A, (a + b) - A, c);
	else
		dfs(a + b, 0, c);

	if (c + a > A)
		dfs(A, b, (c + a) - A);
	else
		dfs(c + a, b, 0);

	if (c + b > B)
		dfs(a, B, (c + b) - B);
	else
		dfs(a, c + b, 0);

	dfs(0, b, a + c);
	dfs(a, 0, b + c);

}


int main()
{
	scanf("%d %d %d", &A, &B, &C);

	dfs(0, 0, C);

	for (int i = 0; i < 21; i++) {
		if (amountC[i])
			printf("%d ", i);
	}
	return 0;
}