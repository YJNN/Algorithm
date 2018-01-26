#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int firstTop[8];
int secondTop[8];
int thirdTop[8];
int fourthTop[8];
int tmpSecondTop[8];
int tmpThirdTop[8];
int k;

int main() {	
	for (int i = 0; i < 8; i++) {
		scanf("%1d", &firstTop[i]);
	}
	for (int i = 0; i < 8; i++) {
		scanf("%1d", &secondTop[i]);
	}
	for (int i = 0; i < 8; i++) {
		scanf("%1d", &thirdTop[i]);
	}
	for (int i = 0; i < 8; i++) {
		scanf("%1d", &fourthTop[i]);
	}
	scanf("%d", &k);
	vector<int> topNum(k);
	vector<int> direct(k);
	for (int i = 0; i<k; i++) {
		scanf("%d %d", &topNum[i], &direct[i]);
	}

	for (int i = 0; i < k; i++) {
		//memset(tmpSecondTop, -2, sizeof(tmpSecondTop));
		//memset(tmpThirdTop, -2, sizeof(tmpThirdTop));
		if (topNum[i] == 2) {
			if (direct[i] == 1) {
				if (secondTop[6] != firstTop[2]) {
					for (int j = 0; j < 7; j++) {
						swap(firstTop[j], firstTop[j + 1]);
					}
				}
				if (secondTop[2] != thirdTop[6]) {
					for (int j = 0; j < 8; j++) {
						tmpThirdTop[j] = thirdTop[j];
					}
					for (int j = 0; j < 7; j++) {
						swap(thirdTop[j], thirdTop[j + 1]);
					}
				}
				else if (secondTop[2] == thirdTop[6]) {
					for (int j = 7; j > 0; j--) {
						swap(secondTop[j], secondTop[j - 1]);
					}
					continue;
				}
				
				if (tmpThirdTop[2] != fourthTop[6]) {
					for (int j = 7; j > 0; j--) {
						swap(fourthTop[j], fourthTop[j - 1]);
					}
				}
				for (int j = 7; j > 0; j--) {
					swap(secondTop[j], secondTop[j - 1]);
				}
			}


			else if (direct[i] == -1) {
				if (secondTop[6] != firstTop[2]) {
					for (int j = 7; j >0; j--) {
						swap(firstTop[j], firstTop[j - 1]);
					}
				}
		
				if (secondTop[2] != thirdTop[6]) {
					for (int j = 0; j < 8; j++) {
						tmpThirdTop[j] = thirdTop[j];
					}
					for (int j = 7; j > 0; j--) {
						swap(thirdTop[j], thirdTop[j - 1]);
					}
				}
				else if (secondTop[2] == thirdTop[6]) {
					for (int j = 0; j < 7; j++) {
						swap(secondTop[j], secondTop[j + 1]);
					}
					continue;
				}


				if (tmpThirdTop[2] != fourthTop[6]) {
					for (int j = 0; j < 7; j++) {
						swap(fourthTop[j], fourthTop[j + 1]);
					}
				}
				for (int j = 0; j < 7; j++) {
					swap(secondTop[j], secondTop[j + 1]);
				}

			}
		}





		else if (topNum[i] == 3) {
			if (direct[i] == 1) {
				if (thirdTop[2] != fourthTop[6]) {
					for (int j = 0; j < 7; j++) {
						swap(fourthTop[j], fourthTop[j + 1]);
					}
				}
			
				if (thirdTop[6] != secondTop[2]) {
					for (int j = 0; j < 8; j++) {
						tmpSecondTop[j] = secondTop[j];
					}
					for (int j = 0; j < 7; j++) {
						swap(secondTop[j], secondTop[j + 1]);
					}
				}
				else if (thirdTop[6] == secondTop[2]) {
					for (int j = 7; j > 0; j--) {
						swap(thirdTop[j], thirdTop[j - 1]);
					}
					continue;
				}
			

				if (tmpSecondTop[6] != firstTop[2]) {
					for (int j = 7; j > 0; j--) {
						swap(firstTop[j], firstTop[j - 1]);
					}
				}
				for (int j = 7; j > 0; j--) {
					swap(thirdTop[j], thirdTop[j - 1]);
				}
			}

			else if (direct[i] == -1) {
				if (thirdTop[2] != fourthTop[6]) {
					for (int j = 7; j >0; j--) {
						swap(fourthTop[j], fourthTop[j - 1]);
					}
				}
			
				if (secondTop[2] != thirdTop[6]) {
					for (int j = 0; j < 8; j++) {
						tmpSecondTop[j] = secondTop[j];
					}
					for (int j = 7; j > 0; j--) {
						swap(secondTop[j], secondTop[j - 1]);
					}
				}
				else if (secondTop[2] == thirdTop[6]) {
					for (int j = 0; j < 7; j++) {
						swap(thirdTop[j], thirdTop[j + 1]);
					}
					continue;
				}
				

				if (tmpSecondTop[6] != firstTop[2]) {
					for (int j = 0; j < 7; j++) {
						swap(firstTop[j], firstTop[j + 1]);
					}
				}
				for (int j = 0; j < 7; j++) {
					swap(thirdTop[j], thirdTop[j + 1]);
				}
			}
			//for (int i = 0; i < 8; i++) {
				//printf("%d", secondTop[i]);
				//printf("\n");
			//}
		}


		else if (topNum[i] == 1) {
			if (direct[i] == 1) {
				if (secondTop[6] != firstTop[2]) {
					for (int i = 0; i < 8; i++) {
						tmpSecondTop[i] = secondTop[i];
					}

					for (int j = 0; j < 7; j++) {
						swap(secondTop[j], secondTop[j + 1]);
					}
				}
				else if (secondTop[6] == firstTop[2]) {
					for (int j = 7; j > 0; j--) {
						swap(firstTop[j], firstTop[j - 1]);
					}
					continue;
				}
				if (tmpSecondTop[2] != thirdTop[6]) {
					for (int i = 0; i < 8; i++) {
						tmpThirdTop[i] = thirdTop[i];
					}
					for (int j = 7; j > 0; j--) {
						swap(thirdTop[j], thirdTop[j - 1]);
					}
				}
				else if (tmpSecondTop[2] == thirdTop[6]) {
					for (int j = 7; j > 0; j--) {
						swap(firstTop[j], firstTop[j - 1]);
					}
					continue;
				}


				if (tmpThirdTop[2] != fourthTop[6]) {
					for (int j = 0; j < 7; j++) {
						swap(fourthTop[j], fourthTop[j + 1]);
					}
				}
				for (int j = 7; j > 0; j--) {
					swap(firstTop[j], firstTop[j - 1]);
				}
					
			}

			else if (direct[i] == -1) {
				if (secondTop[6] != firstTop[2]) {
					for (int i = 0; i < 8; i++) {
						tmpSecondTop[i] = secondTop[i];
					}
					for (int j = 7; j > 0; j--) {
						swap(secondTop[j], secondTop[j - 1]);
					}
				}
				else if (secondTop[6] == firstTop[2]) {
					for (int j = 0; j < 7; j++) {
						swap(firstTop[j], firstTop[j + 1]);
					}
					continue;
				}

				if (tmpSecondTop[2] != thirdTop[6]) {
					for (int i = 0; i < 8; i++) {
						tmpThirdTop[i] = thirdTop[i];
					}
					for (int j = 0; j < 7; j++) {
						swap(thirdTop[j], thirdTop[j + 1]);
					}
				}
				else if (tmpSecondTop[2] == thirdTop[6]) {
					for (int j = 0; j < 7; j++) {
						swap(firstTop[j], firstTop[j + 1]);
					}
					continue;
				}

				if (tmpThirdTop[2] != fourthTop[6]) {
					for (int j = 7; j > 0; j--) {
						swap(fourthTop[j], fourthTop[j - 1]);
					}
				}
				for (int j = 0; j < 7; j++) {
					swap(firstTop[j], firstTop[j + 1]);
				}
			}
		}


		else if (topNum[i] == 4) {
			if (direct[i] == 1) {
				if (fourthTop[6] != thirdTop[2]) {
					for (int i = 0; i < 8; i++) {
						tmpThirdTop[i] = thirdTop[i];
					}
					for (int j = 0; j < 7; j++) {
						swap(thirdTop[j], thirdTop[j + 1]);
					}
				}
				else if (fourthTop[6] == thirdTop[2]) {
					for (int j = 7; j > 0; j--) {
						swap(fourthTop[j], fourthTop[j - 1]);
					}
					continue;
				}
				if (tmpThirdTop[6] != secondTop[2]) {
					for (int i = 0; i < 8; i++) {
						tmpSecondTop[i] = secondTop[i];
					}
					for (int j = 7; j > 0; j--) {
						swap(secondTop[j], secondTop[j - 1]);
					}
				}
				else if (tmpThirdTop[6] == secondTop[2]) {
					for (int j = 7; j > 0; j--) {
						swap(fourthTop[j], fourthTop[j - 1]);
					}
					continue;
				}
				if (tmpSecondTop[6] != firstTop[2]) {
					for (int j = 0; j < 7; j++) {
						swap(firstTop[j], firstTop[j + 1]);
					}
				}
				for (int j = 7; j > 0; j--) {
					swap(fourthTop[j], fourthTop[j - 1]);
				}
			}

			else if (direct[i] == -1) {
				if (fourthTop[6] != thirdTop[2]) {
					for (int i = 0; i < 8; i++) {
						tmpThirdTop[i] = thirdTop[i];
					}
					for (int j = 7; j > 0; j--) {
						swap(thirdTop[j], thirdTop[j - 1]);
					}
				}
				else if (fourthTop[6] == thirdTop[2]) {
					for (int j = 0; j < 7; j++) {
						swap(fourthTop[j], fourthTop[j + 1]);
					}
					continue;

				}
				if (tmpThirdTop[6] != secondTop[2]) {
					for (int i = 0; i < 8; i++) {
						tmpSecondTop[i] = secondTop[i];
					}
					for (int j = 0; j < 7; j++) {
						swap(secondTop[j], secondTop[j + 1]);
					}
				}
				else if (tmpThirdTop[6] == secondTop[2]) {
					for (int j = 0; j < 7; j++) {
						swap(fourthTop[j], fourthTop[j + 1]);
					}
					continue;
				}
				if (tmpSecondTop[6] != firstTop[2]) {
					for (int j = 7; j > 0; j--) {
						swap(firstTop[j], firstTop[j - 1]);
					}
				}
				for (int j = 0; j < 7; j++) {
					swap(fourthTop[j], fourthTop[j + 1]);
				}
			}
		}

	}

	int sum = 0;
	if (firstTop[0] == 1)
		sum += 1;
	if (secondTop[0] == 1)
		sum += 2;
	if (thirdTop[0] == 1)
		sum += 4;
	if (fourthTop[0] == 1)
		sum += 8;

	printf("%d\n", sum);

	return 0;
}