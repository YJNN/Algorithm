#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


int main()
{
	int N, caseNum;

	long long fac[21] = { 1, };
	bool visited[21] = { false, };

	cin >> N;
	cin >> caseNum;
	for (int i = 1; i <= 20; i++) {
		fac[i] = fac[i - 1] * i;
	}

	if (caseNum == 1) {
		long long k;
		cin >> k;
		vector<int> per(N);
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[j] == true)
					continue;
				if (fac[N - i - 1] < k) {
					k -= fac[N - i - 1];
				}
				else {
					per[i] = j;
					visited[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			printf("%d ", per[i]);
		}
		printf("\n");
	}

	else if(caseNum==2){
		long long cnt = 0;
		vector<int> per2(N);
		for (int i = 0; i < N; i++) {
			cin >> per2[i];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < per2[i]; j++) {	
				if (visited[j] == false) {
					cnt += fac[N - i -1];
				}
			}
			visited[per2[i]] = true;
		}
		cout << cnt + 1 << '\n';
	}

	return 0;
}