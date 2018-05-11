#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n;

//recursive
/*
void hanoi(int num, int from, int by, int to) {

	if (num == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		hanoi(num - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(num - 1, by, from, to);
	}
}


int main() {
	scanf("%d", &n);
	printf("%d\n", int(pow(2, n) - 1));
	hanoi(n, 1, 2, 3);


	return 0;
}
*/

//Non-recursive

#define MAX 100
int stack[MAX];
int top;

void initStack() {
	top = -1;
}

int push(int num) {
	if (top >= MAX - 1) {
		printf("Stack Overflow\n");
		return -1;
	}

	stack[++top] = num;
	return num;
}

int pop() {
	if (top < 0) {
		printf("Stack Underflow\n");
		return -1;
	}

	return stack[top--];
}

int isStackEmpty() {
	if (top > -1)
		return 0;
	else
		return 1;
}

void hanoi(int n, int from, int by, int to) {
	initStack();

	while (1) {
		while (n > 1) {
			push(to);
			push(by);
			push(from);
			push(n);
			n--;
			push(to);
			to = by;
			by = pop();
		}
		printf("%d %d\n", from, to);

		if (!isStackEmpty()) {
			n = pop();
			from = pop();
			by = pop();
			to = pop();

			printf("%d %d\n", from, to);

			n--;
			push(from);
			from = by;
			by = pop();
		}
		else {
			break;
		}
	}
}

int main() {
	scanf("%d", &n);
	printf("%d\n", int(pow(2, n) - 1));
	hanoi(n, 1, 2, 3);

	return 0;
}