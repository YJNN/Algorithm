/*
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int N, M;
int map[11][11];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int redX, redY, blueX, blueY;

int main()
{
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; i++) {
			map[i][j] = getchar();
			if (map[i][j] == 'R') {
				redX = i;
				redY = j;
			}
			else if (map[i][j] == 'B') {
				blueX = i;
				blueY = j;
			}
		}
		getchar();
	}

	return 0;
}*/