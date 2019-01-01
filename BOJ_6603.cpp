#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main()
{
	int k;
	while (1) {
		scanf("%d", &k);
		if (k == 0)
			break;
		vector<int> setNum(k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &setNum[i]);
		}

		vector<int> tmp;
		for (int i = 0; i < k - 6; i++) {     ////next_permutation이 오름차순이니까 1부터 먼저 6개넣으면 하나만 나온다!! 111110일테니까.
			tmp.push_back(0);
		}
		for (int i = 0; i < 6; i++) {
			tmp.push_back(1);
		}

		vector< vector<int> > arr;
		do {
			vector<int> cur;
			for (int i = 0; i < k; i++) {
				if (tmp[i] == 1)
					cur.push_back(setNum[i]);
			}
			arr.push_back(cur);
		} while (next_permutation(tmp.begin(), tmp.end()));
		sort(arr.begin(), arr.end());

		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < 6; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		printf("\n");

	}
	return 0;
}