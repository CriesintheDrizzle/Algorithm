#define _CRT_SECURE_NO_WARNINGS

/*
算法：二分算法
ACWing：789. 数的范围
题目地址：https://www.acwing.com/problem/content/791/
*/

#include<iostream>
using namespace std;

const int N = 100010;
int n, q; // n—数组长度 q—查找次数
int num[N];

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	while (q--) {
		int x;
		scanf("%d", &x);
		int l = 0, r = n - 1;

		// 查找满足区间的左端点
		while (l < r) {
			int mid = (l + r) >> 1;
			if (num[mid] >= x) r = mid;
			else l = mid + 1;
		}

		// 判断查找值为空的情况
		if (num[r] != x) cout << "-1 -1" << endl;
		else{ // 查找满足区间的右端点
			cout << r << " ";

			int l = 0, r = n - 1;
			while (l < r) {
				int mid = (l + r + 1) >> 1;
				if (num[mid] <= x) l = mid;
				else r = mid - 1;
			}

			cout << l << endl;
		}

	}



}





