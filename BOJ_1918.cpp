#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX 101

char stack[MAX];
int top;

bool isEmpty() {
	if (top < 0)
		return true;
	else
		return false;
}

void initStack() {
	top = -1;
}

void pop() {
	if (isEmpty()) {
		printf("Empty!!\n");
	}
	else {
		top--;
	}
}

char topp() {
	return stack[top];
}

void push(char c) {
	if (top >= MAX) {
		printf("Stack Overflow\n");
	}
	else {
		stack[++top] = c;
	}
}

int main() {
	char inPut[1000];
	char outPut[1000];
	initStack();
	int outputIndex = 0;
	scanf("%s", inPut);

	for (int i = 0; i < strlen(inPut); i++) {
		//알파벳은 출력에 추가
		if (inPut[i] >= 'A' && inPut[i] <= 'Z') {
			outPut[outputIndex++] = inPut[i];
		}

		//기호일때
		else {
			if (inPut[i] == '(')
				push(inPut[i]);
			else if (inPut[i] == ')') {
				while (topp() != '(') {
					outPut[outputIndex++] = topp();
					pop();
				}
				pop();
				//top--;
			}
			else if (inPut[i] == '*' || inPut[i] == '/') {

				while (!isEmpty() && (topp() == '*' || topp() == '/')) {
					outPut[outputIndex++] = topp();
					pop();
				}
				push(inPut[i]);
			}
			else {
				while (!isEmpty() && topp() != '(') {
					outPut[outputIndex++] = topp();
					pop();
				}
				push(inPut[i]);
			}

		}
	}

	while (!isEmpty()) {
		outPut[outputIndex++] = topp();
		pop();
	}
	outPut[outputIndex] = '\0';
	printf("%s\n", outPut);
	
	return 0;
}