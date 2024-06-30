#include <iostream>
#include <stdio.h>

using namespace std;

/** 두 정수 a, b를 입력한 후에 더 큰값을 반환하는 문제 **/
// 두 정수 중 최댓값을 반환하는 함수
int getMax(int p, int q) {
	if (p > q) {
		return p;
	} else {
		return q;
	}
}

// main 함수
int main() {
	int p, q;	// 입력값 정수 2개

	scanf("%d %d", &p, &q);

	int answer = getMax(p, q);

	printf("%d\n", answer);
	
	return 0;
}
