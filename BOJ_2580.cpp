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

int sudoku[9][9];
bool f, endFlag;

bool isPossible(int X, int Y, int I) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[X][i] == I || sudoku[i][Y] == I)
			return false;
	}
	int nX = (X / 3) * 3;
	int nY = (Y / 3) * 3;
	for (int i = nX; i < nX+3; i++) {
		for (int j = nY; j < nY+3; j++) {
			if (sudoku[i][j] == I)
				return false;
		}
	}
	return true;
}

void dfs() {
	if (endFlag)
		return;
	bool flag = false;
	int a = 0, b = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0) {
				flag = true;
				a = i, b = j;
			}
			if (flag)
				break;
		}
		if (flag)
			break;
	}
	if (!flag) {
		endFlag = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", sudoku[i][j]);
			}
			printf("\n");
		}
		return;
	}

	for (int i = 1; i <= 9; i++) {
		f=isPossible(a, b, i);
		if (f==true) {
			sudoku[a][b] = i;
			dfs();
			sudoku[a][b] = 0;
		}
	}
}

int main() {
	//bool flag = false;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &sudoku[i][j]);
		}
	}
	/*/
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0) {
				dfs(i, j);
			}
		}	
	}*/
	dfs();
	return 0;
}