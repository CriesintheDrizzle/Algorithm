#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

const int N = 100010;

int num[N];

void quicksort(int num[], int l, int r) {
	if (l >= r) return;

	int i = l - 1, j = r + 1, mid = num[(l + r) / 2];
	while (i < j) {
		do i++; while (num[i] < mid);
		do j--; while (num[j] > mid);
		if (i < j)  swap(num[i], num[j]);
	}

	quicksort(num, l, j);
	quicksort(num, j + 1, r);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	quicksort(num, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}

	return 0;
}

