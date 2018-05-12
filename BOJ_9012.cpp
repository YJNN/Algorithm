#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX 51

char stack[MAX];
int top;
int t;

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

void push(char c) {
	if (top >= MAX) {
		printf("Stack Overflow\n");
	}
	else {
		stack[++top] = c;
	}
}



bool checkStr(string s) {
	
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == '(')
			push(c);
		else {
			if (!isEmpty()) {
				pop();
			}
			else {
				return false;
			}
		}
	}
	if (isEmpty())
		return true;
	else
		return false;
}


int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		initStack();
		stack[0] = '\0';

		string str;
		cin >> str;

		if (checkStr(str) == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}