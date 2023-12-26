#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

const int N = 100010;

int num[N];

void quick_sort(int num[], int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = num[(l + r) >> 1];
    while (i < j) {
        do i++; while (num[i] < x);
        do j--; while (num[j] > x);
        if (i < j) swap(num[i], num[j]);
    }

    //递归处理左右两边
    quick_sort(num, l, j);
    quick_sort(num, j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    quick_sort(num, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
}

