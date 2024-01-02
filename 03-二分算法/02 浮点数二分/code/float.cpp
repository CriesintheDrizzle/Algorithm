#define _CRT_SECURE_NO_WARNINGS

/*
Acwing-790. 数的三次方根
题目链接：https://www.acwing.com/problem/content/792/
给定一个浮点数 n，求它的三次方根。
*/

#include<iostream>
using namespace std;

int main() {
	double x;
	cin >> x;

	double l = -10000;
	double r = 10000;

	while (r-l > 1e-8) {
		double mid = (l + r) / 2;
		if (mid * mid * mid <= x) l = mid;
		else r = mid;
	}

	printf("%.6lf", l);
	return 0;
}