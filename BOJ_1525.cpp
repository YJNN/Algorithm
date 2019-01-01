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

int num;
//bool visited[1000000000];    배열로 상태를 저장하려고 했으나 너무 크기때문에 비효율적임.
//int dist[1000000000];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
string a;

int main()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &num);
			if (num == 0)
				num = 9;
			string tmp = to_string(num);
			a += tmp;
		}
	}
	int fst = stoi(a);	
	map<int, int> dist;
	queue<int> q;
	q.push(fst);
	dist[fst] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		string nowN = to_string(now);
		int tmp = nowN.find('9');
		int x = tmp / 3;
		int y = tmp % 3;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) {
				string temp = nowN;
				swap(temp[3*x+y], temp[3*nx+ny]);
				int tmpNum = stoi(temp);
				if (dist.count(tmpNum) == 0) {     //count는 요소의 갯수를 리턴
					q.push(tmpNum);
					dist[tmpNum] = dist[now] + 1;
				}

			}
		}
	}
	if (dist.count(123456789) == 0)
		printf("%d\n", -1);
	else
		printf("%d\n", dist[123456789]);

	return 0;
}