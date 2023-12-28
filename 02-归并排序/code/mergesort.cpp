#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

const int N = 100010;
int num[N], tmp[N];

void mergesort(int num[], int l, int r) {
	if (l >= r) return;

	int mid = (l + r) >> 1;
	mergesort(num, l, mid); mergesort(num, mid + 1, r);

	// 归并
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (num[i] <= num[j]) tmp[k++] = num[i++];
		else tmp[k++] = num[j++];
	}

	while (i <= mid) tmp[k++] = num[i++];
	while (j <= r) tmp[k++] = num[j++];

	// 复制回原数组
	for (int i = l, j = 0; i <= r; i++, j++) {
		num[i] = tmp[j];
	}
	
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	mergesort(num, 0, n - 1);

	for (int i = 0; i < n; i++){
		printf("%d ", num[i]);
	}

	return 0;
}